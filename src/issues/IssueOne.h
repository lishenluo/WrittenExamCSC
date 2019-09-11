/**
*  ����һ�������ַ����к���֤50�����ֵ����Сֵ��ƽ��ֵ����λ������׼������ϵ����(���ݿɲμ�data.csv)
*
*  @author lishenluo
*  @since  2019-01-12
*/

#pragma once

#include "stdafx.h"

namespace csc
{
    
    enum CALC_TYPE
    {
        MAX_DATA = 0, //���ֵ
        MIN_DATA,     //��Сֵ
        AVG_DATA,     //ƽ��ֵ
        MEDIAN_DATA,  //��λ��
        STD_DATA,     //��׼��
        CORR_DATA = 5,//���ϵ��
    };

    enum DATA_TYPE
    {
        INDEX,        //ָ��
        STOCK,        //��Ʊ
    };

    typedef struct _mt
    {
        vector<string> date;       //����
        vector<double> indexClose; //ָ������
        vector<double> stockClose; //��Ʊ����

    }MarketData;

    class IssueOne
    {
    public:
        IssueOne(const string& dataFile); //���������ļ��������
        void showIssueOneResult();        //��ʾ������

        //���Խӿ�
        bool  isEmpeyOfNeedCalcData();
        void setNeedCalcData(const string& index, const string& stock, const vector<double> indexData, const vector<double> stockData);
        double getMathValue(DATA_TYPE dataType, CALC_TYPE calcType);
    private:
        void readMarketDataFromCSV(); //��ȡdata.csv������
        double calcMathValue(DATA_TYPE dataType, CALC_TYPE calcType);//�������ͳ��ֵ
        double calcCorrelation();     //�������ϵ��
    private:
        MarketData m_needCalcData; //data.csv������
        string m_dataFile;         //data.csv�ļ�·�����ļ�
        string m_index;            //ָ������
        string m_stock;            //��Ʊ����
    };
}
