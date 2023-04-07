/*
 * 1991 - 트리 순회
 *
 *최초 배열로 구현하였으나 최악의 경우 2의 26승만큼의 메모리가 필요해진다.
 *(2^26 = 67,108,864 바이트 약 70메가)
 *
 *따라서 Root Left Right char를 가지는 노드를 작성하여 트리를 만들어나간다
 *입력된 노드는 다시 편하게 접근 가능하도록 각 알파벳를 배열로 매핑하여 기록해둔다
 *(즉, A는 0 Z는 25인것이다. )
 *
 *A에 접근한다면 배열 인덱스 0을통해 열어보고 거기서 Left가 B라면
 *1번 인덱스로 다시 접근한다.
 *
 *이를 이용해 전위 중위 후위 순회를 재귀로 구현한다.
 *
 *배열 인덱스 범위를 벗어나는 경우를 주의해야한다.
 *('.'은 'A'보다 작아 '.'-'A'는 음수를 발생시킨다.)
 *
 */

#include <iostream>

using namespace std;

struct _char3
{
	char Root;
	char Left;
	char Right;
};

_char3 TreeOfArray[26]{};

void Preorder(int const IndexOfRoot)
{
	if (IndexOfRoot < 0 or TreeOfArray[IndexOfRoot].Root == '.')
	{
		return;
	}
	cout << TreeOfArray[IndexOfRoot].Root;
	Preorder(TreeOfArray[IndexOfRoot].Left - 'A');
	Preorder(TreeOfArray[IndexOfRoot].Right - 'A');
}
void Inorder(int const IndexOfRoot)
{
	if (IndexOfRoot < 0 or TreeOfArray[IndexOfRoot].Root == '.')
	{
		return;
	}
	Inorder(TreeOfArray[IndexOfRoot].Left - 'A');
	cout << TreeOfArray[IndexOfRoot].Root;
	Inorder(TreeOfArray[IndexOfRoot].Right - 'A');
}
void Postorder(int const IndexOfRoot)
{
	if (IndexOfRoot < 0 or TreeOfArray[IndexOfRoot].Root == '.')
	{
		return;
	}
	Postorder(TreeOfArray[IndexOfRoot].Left - 'A');
	Postorder(TreeOfArray[IndexOfRoot].Right - 'A');
	cout << TreeOfArray[IndexOfRoot].Root;
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfInput = 0;

	cin >> CountOfInput;

	while (CountOfInput--)
	{
		char Root{};
		_char3 Edge{};
		cin >> Edge.Root >> Edge.Left >> Edge.Right;

		int const IndexOfRoot = Edge.Root - 'A';
		TreeOfArray[IndexOfRoot] = Edge;
	}
	Preorder(0);
	cout << "\n";
	Inorder(0);
	cout << "\n";
	Postorder(0);
	return 0;
}

/*
 *배열로 구현
 *
 *배열로 작성한 구성한 경우 다음과 같은 규칙으로 작성한다.
 *최악의 경우 왼쪽으로만 성장하는 트리를 고려해야 한다.(2^26 = 67,108,864 바이트 약 70메가)
 *
 *									A(1)
 *						B(2)					C(3)
 *					D(4)	E(5)			F(6)	G(7)
 *				H(8)I(9)	J(10)K(11)		L(12)M(13)	N(14)O(15)
 *
 *
 *배열을 만들어 트리를 구성한다
 *
 *위와 같이 최초 삽입되는 Root 는 1로 시작한다(0)
 *1부터 시작 시켜 Root와 Left는 2배 관계를 가지도록 만든다
 *
 *
 *
 *예제
 *									A(1)
 *						B(2)					C(3)
 *					D(4)	.(5)			E(6)	F(7)
 *				.(8).(9)	.(10).(11)		.(12).(13)	.(14)G(15)
 *
 */
 //
 //#include <iostream>
 //#include <vector>
 //
 //using namespace std;
 //
 //
 //vector<char> TreeOfArray{}; //70메가 필요
 //int LocationOfNodes[26]{}; //노드는 A~Z
 //
 //int GetLeftIndex(int const IndexOfRoot)
 //{
 //	return IndexOfRoot * 2;
 //}
 //int GetRightIndex(int const IndexOfRoot)
 //{
 //	return (IndexOfRoot * 2)+1;
 //}
 //
 //void SetNode(char const Node, int const IndexOfTree)
 //{
 //	int const AlphabetToIndex = static_cast<int>(Node - 'A');
 //	LocationOfNodes[AlphabetToIndex] = IndexOfTree;
 //	TreeOfArray[IndexOfTree] = Node;
 //}
 //
 //void Preorder(int const IndexOfRoot)
 //{
 //	if(TreeOfArray[IndexOfRoot]=='.')
 //	{
 //		return;
 //	}
 //	cout << TreeOfArray[IndexOfRoot];
 //	Preorder(GetLeftIndex(IndexOfRoot));
 //	Preorder(GetRightIndex(IndexOfRoot));
 //}
 //void Inorder(int const IndexOfRoot)
 //{
 //	if (TreeOfArray[IndexOfRoot] == '.')
 //	{
 //		return;
 //	}
 //	Inorder(GetLeftIndex(IndexOfRoot));
 //	cout << TreeOfArray[IndexOfRoot];
 //	Inorder(GetRightIndex(IndexOfRoot));
 //}
 //void Postorder(int const IndexOfRoot)
 //{
 //	if (TreeOfArray[IndexOfRoot] == '.')
 //	{
 //		return;
 //	}
 //	Postorder(GetLeftIndex(IndexOfRoot));
 //	Postorder(GetRightIndex(IndexOfRoot));
 //	cout << TreeOfArray[IndexOfRoot];
 //}
 //int main()
 //{
 //	cin.tie(nullptr);
 //	ios_base::sync_with_stdio(false);
 //	TreeOfArray.resize(1000);
 //	int CountOfInput = 0;
 //
 //	cin >> CountOfInput;
 //
 //	//항상 Root는 A, 루트는 항상 존재한다
 //	SetNode('A', 1);
 //
 //	while (CountOfInput--)
 //	{
 //		char Root{}, Left{}, Right{};
 //		cin >> Root >> Left >> Right;
 //
 //		int const IndexOfRoot = LocationOfNodes[Root - 'A'];
 //		SetNode(Left, GetLeftIndex(IndexOfRoot));
 //		SetNode(Right, GetRightIndex(IndexOfRoot));
 //	}
 //	Preorder(1);
 //	cout << "\n";
 //	Inorder(1);
 //	cout << "\n";
 //	Postorder(1);
 //	return 0;
 //}