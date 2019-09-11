#include"IssueTwo.h"

namespace csc
{
    IssueTwo::IssueTwo()
    {
    }

    void IssueTwo::setList()
    {
        cout << "�����һ�������Կո�������� -1 0 5 -2 3 5 0 0���Իس�������:" << endl;
        cout << ":";
        double num;
        while (cin >> num)
        {
            m_list.emplace_back(num);
            if (cin.get() == '\n')
                break;
        }
    }

    void IssueTwo::showIssueTwoResult()
    {
        calcMaxSumSubList();
        cout << "�����������Ϊ:" << endl;
        for (size_t index = 0; index < m_list.size(); ++index)
        {
             if (index == m_list.size()-1)
             {
                 cout << m_list[index] << endl;
             }
             else
             {
                 cout << m_list[index] << " ";
             }
        }
        cout <<endl << "���������еĺ͵����ֵΪ:" << m_maxSubSum << endl;
        cout << "��Ӧ����������:" << endl;
        int j = 1;
        for (set<pair<size_t, size_t> >::iterator it = m_maxSubListPosition.begin(); it != m_maxSubListPosition.end(); ++it)
        {
            cout <<j++<< ".λ��:[" << (*it).first << "," << (*it).second << "],������:";
            for (size_t ind = (*it).first; ind <= (*it).second; ++ind)
            {
                cout << m_list[ind];
                if (ind !=(*it).second)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    void IssueTwo::setList(const vector<double>&listData)
    {
        m_list = listData;
        calcMaxSumSubList();
    }

    double IssueTwo::getMaxSubSum()
    {
        return m_maxSubSum;
    }

    int IssueTwo::getSizeOfMaxSubListPosition()
    {
        return (int)m_maxSubListPosition.size();
    }

    void IssueTwo::calcMaxSumSubList()
    {
        //�㷨˵��dp[n] = max(0, dp[n-1]) + num[n]
        //������һЩ�������
        //������������ֵ���Ӧ���������������������У�ʱ�临�Ӷ�O(2N)
        //����O(N^2):ȫ����0�����

        m_maxSubListPosition.clear();
        if (m_list.empty())
        {
            return;
        }

        //��������ж�
        if (m_list.size() == 1)
        {
            m_maxSubListPosition.insert(pair<size_t, size_t>(0, 0));
            m_maxSubSum = m_list[0];
            return;
        }

        vector<double> midList(m_list);
        m_maxSubSum = midList[1];
        //midList: -1 0 1 2 -1 -1 -1 1 1 1 0
        for (size_t index = 1; index < midList.size(); ++index) 
        {
            //Ѱ������
            if (midList[index - 1] > 0)
            {
                midList[index] += midList[index - 1];
            }
            else if(midList[index - 1] > midList[index])
            {
                midList[index] = midList[index - 1];
            }

            if (midList[index] > m_maxSubSum)
            {
                m_maxSubSum = midList[index];
            }
        }

        size_t start = -1;
        size_t end = -1;
        size_t all_start = -1;
        vector<size_t> startVec;
        //after Ѱ������ now midList: -1 0 1 3 2 1 0 1 2 3 3
        for (size_t index = 0; index < midList.size(); ++index)
        {
            //Ѱ����������������������
            if (all_start == -1 && (midList[index] >= 0))//�����е�һ���Ǹ���λ��//����ʼ�Ǹ��������
            {
                all_start = index;
            }
            if (midList[index] == 0)//�ﵽ0��λ�ã��������0��ǰ���ֵ�ۼƵõ�0
            {
                startVec.emplace_back(index);
            }
            if (midList[index] != m_maxSubSum)
            {
                continue;
            }

            //�ﵽ���ֵ��λ��

            //��Ϊ0��λ��
            if (startVec.empty())
            {
                size_t st = ((all_start == -1) ? index : all_start);
                m_maxSubListPosition.insert(pair<size_t, size_t>(st, index));
                continue;
            }

            //��Ϊ0��λ��
            bool hasOriZero = false;//ԭʼ����λ�þ���0
            for (size_t ind = 0; ind < startVec.size(); ++ind)
            {
                if (m_list[startVec[ind]] == 0)//ԭʼ���еĸ�λ���Ͼ���0
                {
                    m_maxSubListPosition.insert(pair<size_t, size_t>(startVec[ind], index));
                    hasOriZero = true;
                }
                else if(!hasOriZero && all_start !=-1 )
                {
                    m_maxSubListPosition.insert(pair<size_t, size_t>(all_start, index));
                }
                if (startVec[ind] + 1 <= index)
                {
                    m_maxSubListPosition.insert(pair<size_t, size_t>(startVec[ind] + 1, index));
                }
            }
        }
    }

}

