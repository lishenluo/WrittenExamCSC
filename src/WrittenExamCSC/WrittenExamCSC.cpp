// WrittenExamCSC.cpp : �������̨Ӧ�ó������ڵ㡣

#include "IssueOne.h"
#include "IssueTwo.h"
#include "IssueThree.h"
#include "IssueFour.h"
using namespace csc;
int main()
{
    cout << "����һ�������ַ����к���֤50�����ֵ����Сֵ��ƽ��ֵ����λ������׼������ϵ��" << endl<<endl;
    cout << "���������һ���У���������Ԫ�ؿ����ɸ�������������������еĺ͵����ֵ����Ӧ������" << endl<<endl;
    cout << "����������дһ�����򣬸ó�������ʱ��CPU��ʹ����Ϊ����ͼ��" << endl<<endl;
    cout << "�����ģ������ݿ�����һ��������ñ������У���Ʊ���ƣ����ڣ������������̼�." << endl << "����Ҫ�����ĳֻ��Ʊ5���ƶ�ƽ���ۣ���5�ս�������Ȩ�ƶ�ƽ����" << endl<<endl;
    cout << "���������1��2��3��4���Իس�����������ʼ����,����5����" << endl;
    cout << ":";
    int num;
    while (cin >> num)
    {
        bool end = false;
        switch (num)
        {
            case 1:
            {
                IssueOne issueOne = IssueOne("../datadir/data.csv");
                issueOne.showIssueOneResult();
                break;
            }
            case 2:
            {
                IssueTwo issueTwo;
                issueTwo.setList();
                issueTwo.showIssueTwoResult();
                break;
            }
            case 3:
            {
                cout << "����3��������ѭ��,����رյ��Ը��������������������۲�cpuʹ�����" << endl;
                cout << "������ѭ�������ֶ�ֹͣ���У��Ƿ����(y/n)" << endl;
                cout << "����y �� n ��س�:";
                char doit;
                while (1)
                {
                    cin >> doit;
                    if ('y' == doit) break;
                    else if ('n' == doit) break;
                    else
                        cout << "�������" << endl << "����y �� n ��س� :";
                }
                if (doit == 'y')
                {
                    IssueThree issueThree;
                    issueThree.showCosGraphOfCPU();
                }
                break;
            }
            case 4:
            {
                IssueFour issueFour("../datadir/MarketDataCSC.db");
                issueFour.openSqliteDatabase();
                const char* sql = "CREATE TABLE MarketData("\
                "StockCode  CAHR(9)      NOT NULL, "\
                "DateTime   TEXT(20)    NOT NULL, "\
                "close      REAL(11, 4)     NOT NULL, "\
                "volume     INTEGER(11)     NOT NULL );";
                issueFour.deleteTable("MarketData");
                issueFour.creatTable(sql);
                issueFour.readMarketDataFromCSV("../datadir/SZ000002.csv", "000002.SZ");
                issueFour.insertDataToDB("MarketData","StockCode, DateTime, close, volume");
                issueFour.selectOptim("MarketData","DateTime");
                issueFour.closeSqliteDatabase();
                issueFour.showMovingAvg(5, NORMAL);
                cout << endl;
                issueFour.showMovingAvg(5, VOL_WEIGHT);
                break;
            }
            case 5:
            {
                end = true;
                break;
            }
            default:
                cout << "���벻��" << endl;
        }
        if (end)
        {
            cout << "������" << endl;
            break;
        }
        cout << "*****************************************************************************************" << endl;
        cout << endl<<"���������1��2��3��4���Իس�����������������,����5����" << endl;
        cout << ":";
    }
    return 0;
}
