/*
 *9935 - ���ڿ� ����
 *
 *find�� erase�� ����Ѵٸ� �ش� ���ڿ� �Ѱ��� ã�Ƽ� �����ϴµ��ٰ�
 *O(mn)�� �ð����⵵�� �����Ƿ� (m�� ��ü ���ڿ�����, n�� ã�� ���ڿ� ����)
 *�ð��ʰ��� �߻��Ѵ�.
 *
 *���ڿ��� ����ó�� �Ẹ��
 *
 *ó������ ���ο� ���ڿ��� �ϳ��� �����鼭
 *Bomb���ڿ��� ��ġ�Ѵٸ� �̾Ƴ��� ������ �����غ���
 *������ �ѹ� ������ �Ͼ �� ������ ���ڿ��� �ٽ� ��ź�� �Ǵ� ��츦 ��� ó���ұ�
 *
 *CCCCCC444444 �Ǵ� 12ab112ab2ab�� ��츦 ����
 *
 *������ �����غ��� �� C4�� 4�� 12ab�� b�� �˻��ȣ�� �ȴ�
 *��, �տ������� ����ϴٰ� 4�� ������ 4�� ������ �ι��ڰ� C4���� Ȯ���Ѵ�
 *12ab ��� b�� ������ �̰��� �˻��ȣ�� �Ǿ� b�κ��� �� �ױ��ڸ� 12ab���� �Ǻ��ϰ� �����Ѵ�
 *�̷��� �Ǹ� C4�� ������ �� �ٽ� 4�� ���� ������ ���ڿ��� �ձ��ڸ� �ٽ� ���� ����������
 *
 *
 */

#include <iostream>
#include <string>


using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string inputStr{};
	string bombStr{};
	string result{};
	cin >> inputStr>>bombStr;

	for(int i=0; i<inputStr.size(); i++)
	{
		char const lastChar = inputStr[i];
		result += lastChar;
		if(lastChar == bombStr[bombStr.size()-1] and result.size()>=bombStr.size())
		{
			int count = 0;
			int startIndex = static_cast<int>(result.size() - bombStr.size());
			for(int i=0; i< bombStr.size(); i++)
			{
				if (result[startIndex + i] == bombStr[i])
					count++;
			}
			if(count == bombStr.size())
			{
				result.erase(result.begin() + startIndex, result.end());
			}

		}
	}
	if (result.empty())
		cout << "FRULA";
	else
		cout << result;


	return 0;
}