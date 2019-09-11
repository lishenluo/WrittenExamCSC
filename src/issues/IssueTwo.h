/**
*  ���������һ���У���������Ԫ�ؿ����ɸ�������������������еĺ͵����ֵ����Ӧ������
*
*  @author lishenluo
*  @since  2019-1-12
*/

#pragma once

#include "stdafx.h"

namespace csc
{
    class IssueTwo
    {
    public:
        IssueTwo();
        void setList();             //��������
        void showIssueTwoResult();  //չʾ���

        //���Խӿ�
        void setList(const vector<double>&listData);
        double getMaxSubSum();
        int getSizeOfMaxSubListPosition();

    private:
        void calcMaxSumSubList();   //���������к�����
    private:
        vector<double>                  m_list;                  //ԭʼ����
        set<pair<size_t, size_t> >      m_maxSubListPosition;    //���������������еĿ�ʼ�ͽ����±�
        double                          m_maxSubSum;             //��������������
    };
}
