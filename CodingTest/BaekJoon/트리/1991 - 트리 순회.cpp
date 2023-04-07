/*
 * 1991 - Ʈ�� ��ȸ
 *
 *���� �迭�� �����Ͽ����� �־��� ��� 2�� 26�¸�ŭ�� �޸𸮰� �ʿ�������.
 *(2^26 = 67,108,864 ����Ʈ �� 70�ް�)
 *
 *���� Root Left Right char�� ������ ��带 �ۼ��Ͽ� Ʈ���� ��������
 *�Էµ� ���� �ٽ� ���ϰ� ���� �����ϵ��� �� ���ĺ��� �迭�� �����Ͽ� ����صд�
 *(��, A�� 0 Z�� 25�ΰ��̴�. )
 *
 *A�� �����Ѵٸ� �迭 �ε��� 0������ ����� �ű⼭ Left�� B���
 *1�� �ε����� �ٽ� �����Ѵ�.
 *
 *�̸� �̿��� ���� ���� ���� ��ȸ�� ��ͷ� �����Ѵ�.
 *
 *�迭 �ε��� ������ ����� ��츦 �����ؾ��Ѵ�.
 *('.'�� 'A'���� �۾� '.'-'A'�� ������ �߻���Ų��.)
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
 *�迭�� ����
 *
 *�迭�� �ۼ��� ������ ��� ������ ���� ��Ģ���� �ۼ��Ѵ�.
 *�־��� ��� �������θ� �����ϴ� Ʈ���� ����ؾ� �Ѵ�.(2^26 = 67,108,864 ����Ʈ �� 70�ް�)
 *
 *									A(1)
 *						B(2)					C(3)
 *					D(4)	E(5)			F(6)	G(7)
 *				H(8)I(9)	J(10)K(11)		L(12)M(13)	N(14)O(15)
 *
 *
 *�迭�� ����� Ʈ���� �����Ѵ�
 *
 *���� ���� ���� ���ԵǴ� Root �� 1�� �����Ѵ�(0)
 *1���� ���� ���� Root�� Left�� 2�� ���踦 �������� �����
 *
 *
 *
 *����
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
 //vector<char> TreeOfArray{}; //70�ް� �ʿ�
 //int LocationOfNodes[26]{}; //���� A~Z
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
 //	//�׻� Root�� A, ��Ʈ�� �׻� �����Ѵ�
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