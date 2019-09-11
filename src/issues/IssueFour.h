/**
*  �����ģ������ݿ�����һ��������ñ������У���Ʊ���ƣ����ڣ������������̼ۡ�����Ҫ�����ĳֻ��Ʊ5���ƶ�ƽ���ۣ���5�ս�������Ȩ�ƶ�ƽ���ۡ�
*  (�ƶ�ƽ��������μ�https://zh.wikipedia.org/wiki/%E7%A7%BB%E5%8B%95%E5%B9%B3%E5%9D%87���븽�Ͻ������Ͳ�ѯ����SQL)
*  
*  ˼·��1.��sqlite�����������ݿ�����ݿ��
*        2.��000002.SZ.csv�����ݶ����ڴ沢�����ݲ������ݿ����
*        3.���������5���ƶ�ƽ����
*        4.ֱ��ͨ��sql�����ƶ�ƽ���������Ȳ�����
*  
*  @author lishenluo
*  @since  2019-01-12
*/

#pragma once

#include "stdafx.h"
#include <sqlite\sqlite3.h>

namespace csc
{
    typedef struct _st
    {
        string stockCode;
        vector<string> date;       //����
        vector<double> close;      //���̼�
        vector<r_int64> volume;    //���̼�
        bool isSameSize() {
            return (date.size() == close.size() && close.size() == volume.size());
        };
    }StockData;

    enum MOVING_AVG_TYPE
    {
        NORMAL,
        VOL_WEIGHT,
    };

    typedef int(*callback)(void*, int, char**, char**);

    class IssueFour
    {
    public:
        IssueFour(const string& sqlDatabaseFile);
        bool openSqliteDatabase();
        bool closeSqliteDatabase();
        bool creatTable(const char* sql);
        bool deleteTable(const string& tableName);
        bool insertDataToDB(const string& tableName, const string& columns);
        void readMarketDataFromCSV(const string&dataFile,const string&stockCode); //��ȡcsv������
        void select(const string& tableName, const string& orderColumn="");
        void selectOptim(const string& tableName, const string& orderColumn="");
        bool showMovingAvg(int period, MOVING_AVG_TYPE type);
        void showSelectData();
    private:
        int exec(const char* sql, string& errMsg, callback callb = NULL, void* data=NULL);
        bool insertValue(const string& tableName, const string&columns, const string&values);
        static int callBack(void *data, int argc, char **argv, char **azColName);
    private:
        string              m_sqlDatabaseFile;
        sqlite3*            m_marketDataDB;
        StockData           m_stockData;
        StockData           m_stockDataSelect;
    };
}
