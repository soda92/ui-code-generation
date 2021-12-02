//MSVC 中文乱码解决
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "realtimedatawidget.h"
#include "ui_realtimedatawidget.h"

RealTimeDataWidget::RealTimeDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealTimeDataWidget)
{
    ui->setupUi(this);

    layout()->setContentsMargins(3,3,3,3);
    ui->stackedWidget->layout()->setContentsMargins(0,0,0,0);

    //// 6A
    model_6A_zhidong = new QStandardItemModel;
    model_6A_fanghuo = new QStandardItemModel;
    for(int i=0;i<7;i++)
    {
        model_6A_zouxing[i] = new QStandardItemModel;

    }
    model_6A_shipin[0] = new QStandardItemModel;
    model_6A_shipin[1] = new QStandardItemModel;
    model_6A_banben = new QStandardItemModel;
    model_6A_liaowang = new QStandardItemModel;
    model_6A_youwei = new QStandardItemModel;
    model_6A_pingtai = new QStandardItemModel;

    //制动
    ui->tableView_rt_zhidong->setModel(model_6A_zhidong);
    ui->tableView_rt_zhidong->horizontalHeader()->hide();
    ui->tableView_rt_zhidong->verticalHeader()->hide();
    ui->tableView_rt_zhidong->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_zhidong->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //防火
    ui->tableView_rt_fanghuo->setModel(model_6A_fanghuo);
    ui->tableView_rt_fanghuo->horizontalHeader()->hide();
    ui->tableView_rt_fanghuo->verticalHeader()->hide();
    ui->tableView_rt_fanghuo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_fanghuo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //走行
        //温度表
    ui->tableView_rt_zouxing_wd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_zouxing_wd->setModel(model_6A_zouxing[0]);
    QStringList hheaders,vheaders;
    hheaders<<"1位"<<"2位"<<"3位"<<"4位"<<"5位"<<"6位"<<"环温1"<<"环温2";
    vheaders<<"1轴"<<"2轴"<<"3轴"<<"4轴"<<"5轴"<<"6轴";
    model_6A_zouxing[0]->setHorizontalHeaderLabels(hheaders);
    model_6A_zouxing[0]->setVerticalHeaderLabels(vheaders);
    ui->tableView_rt_zouxing_wd->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //轴报警情况
    for(int i=1;i<7;i++)
    {
        QStringList hheaders2,vheaders2;
        hheaders2<<"温升报警"<<"超温报警"<<"轴承I级"<<"轴承II级"<<"齿轮I级"<<"齿轮II级"<<"踏面I级"<<"踏面II级";
        vheaders2<<"1位"<<"2位"<<"3位"<<"4位"<<"5位"<<"6位";
        model_6A_zouxing[i]->setHorizontalHeaderLabels(hheaders2);
        model_6A_zouxing[i]->setVerticalHeaderLabels(vheaders2);
    }
    ui->tableView_rt_zouxing_zbj->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[1]);
    ui->tableView_rt_zouxing_zbj->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //视频
        //状态
    ui->tableView_rt_shipin_status->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_shipin_status->setModel(model_6A_shipin[0]);
    ui->tableView_rt_shipin_status->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_shipin_status->horizontalHeader()->hide();
    ui->tableView_rt_shipin_status->verticalHeader()->hide();
        //通道
    ui->tableView_rt_shipin_tongdao->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_shipin_tongdao->setModel(model_6A_shipin[1]);
    ui->tableView_rt_shipin_tongdao->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList hheaders3,vheaders3;
    hheaders3<<"01"<<"02"<<"03"<<"04"<<"05"<<"06"<<"07"<<"08"<<"09"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16";
    vheaders3<<"通道名称"<<"通道自检状态"<<"通道使能";
    model_6A_shipin[1]->setHorizontalHeaderLabels(hheaders3);
    model_6A_shipin[1]->setVerticalHeaderLabels(vheaders3);

    //版本
    ui->tableView_rt_banben->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_banben->setModel(model_6A_banben);
    ui->tableView_rt_banben->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_banben->horizontalHeader()->hide();
    ui->tableView_rt_banben->verticalHeader()->hide();

    //瞭望
    ui->tableView_rt_liaowang->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_liaowang->setModel(model_6A_liaowang);
    ui->tableView_rt_liaowang->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_liaowang->horizontalHeader()->hide();
    ui->tableView_rt_liaowang->verticalHeader()->hide();

    //油位
    ui->tableView_rt_youwei->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_youwei->setModel(model_6A_youwei);
    ui->tableView_rt_youwei->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_youwei->horizontalHeader()->hide();
    ui->tableView_rt_youwei->verticalHeader()->hide();

    //平台
    ui->tableView_rt_pingtai->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_pingtai->setModel(model_6A_pingtai);
    ui->tableView_rt_pingtai->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_pingtai->horizontalHeader()->hide();
    ui->tableView_rt_pingtai->verticalHeader()->hide();


    //// LKJ
    model_lkj = new QStandardItemModel;
    ui->tableView_rt_lkj->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_lkj->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_lkj->setModel(model_lkj);
    ui->tableView_rt_lkj->horizontalHeader()->hide();
    ui->tableView_rt_lkj->verticalHeader()->hide();

    //// TCMS
    for(int i=0;i<6;i++)
    {
        QHBoxLayout* hlayout=new QHBoxLayout;
        tablev[i]=new QTableView;
        hlayout->addWidget(tablev[i]);
        hlayout->setContentsMargins(0,0,0,0);
        ui->tabWidget_rt_tcms->widget(i)->setLayout(hlayout);
        model_tcms[i] = new QStandardItemModel;
        tablev[i]->setModel(model_tcms[i]);
        tablev[i]->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tablev[i]->horizontalHeader()->hide();
        tablev[i]->verticalHeader()->hide();
        tablev[i]->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }


    //BD
    model_bd = new QStandardItemModel;
    ui->tableView_rt_bd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_rt_bd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_rt_bd->setModel(model_bd);
    ui->tableView_rt_bd->horizontalHeader()->hide();
    ui->tableView_rt_bd->verticalHeader()->hide();

    startGetData=false;
    currentQuerytrainNo=0;
    std::thread thread1(thread_getdata,this);
    thread1.detach();
}

RealTimeDataWidget::~RealTimeDataWidget()
{
    delete ui;
}

void RealTimeDataWidget::setCurrWidget(int x)
{
    if(x>=ui->stackedWidget->count())
        return;

    ui->stackedWidget->setCurrentIndex(x);
}

string strhex(unsigned char* data, int size)
{
    string str;
    for(int i=0;i<size;i++)
    {
        unsigned char chr = data[i];
        if(chr/16<10){
            str+=std::to_string(chr/16);
        }
        else {
            str+=(char)((chr/16-10)+'A');
        }

        if(chr%16<10){
            str+=std::to_string(chr%16);
        }
        else {
            str+=(char)((chr%16-10)+'A');
        }
    }
    return str;
}

void RealTimeDataWidget::thread_getdata(RealTimeDataWidget *rtdw)
{
    //定时获取实时数据
    while (1) {
        if(!rtdw->startGetData && rtdw->currentQuerytrainNo==0)
        {
            continue;
            Sleep(1000);
        }
        qDebug()<<"flush data!";
        MyDatabase db;

        db.connect();

        QString sql=QString("SELECT ID,inTIME,trainType,trainNo,longitude,latitude,altitude,speed,GPSTime,data_6a,data_lkj,data_tcms "
                            "from cmd_data "
                            "where ID = (SELECT MAX(ID) from cmd_data where trainNo = '%1');").arg(rtdw->currentQuerytrainNo);

        QList<QList<QVariant>> data;
        if(!db.query(sql,&data))
        {
            //QMessageBox::warning(rtdw,"warning","query failed");
            //qDebug()<<"query failed";
            Sleep(10*1000);
            continue;
        }

        for(auto i = data.begin();i!=data.end();i++)
        {
            qDebug()<<i->value(0).toString();
            qDebug()<<i->value(1).toDateTime().toString("yyyy-MM-dd hh:mm:ss");

            //北斗
            QList<QStandardItem*> itemlist;
            for(int i=0;i<18;i++)
            {
                QStandardItem *item =new QStandardItem;
                itemlist.push_back(item);
                rtdw->model_bd->setItem(i/4,i%4,item);
                if(i%2==0)
                {
                    item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
                    item->setBackground(QBrush(RGB(234,239,240)));
                }
            }
            int n=0;
            itemlist.value(n++)->setText("车型：");
            itemlist.value(n++)->setText(i->value(2).toString());
            itemlist.value(n++)->setText("车号：");
            itemlist.value(n++)->setText(i->value(3).toString());
            itemlist.value(n++)->setText("经度：");
            itemlist.value(n++)->setText(QString("%1").arg(i->value(4).toDouble()/200000));
            itemlist.value(n++)->setText("纬度：");
            itemlist.value(n++)->setText(QString("%1").arg(i->value(5).toDouble()/200000));
            itemlist.value(n++)->setText("海拔：");
            itemlist.value(n++)->setText(i->value(6).toString());
            itemlist.value(n++)->setText("速度：");
            itemlist.value(n++)->setText(i->value(7).toString());
            itemlist.value(n++)->setText("时间：");
            itemlist.value(n++)->setText(i->value(8).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
            itemlist.clear();

            //6A
            QByteArray arr = i->value(9).toByteArray();
            char* data = arr.data();
            int len = arr.length();
            string str = strhex((unsigned char*)data,len);
            qDebug()<<"len="<<len<<"\n[[["<<QString::fromStdString(str);
            if(len != sizeof (Data6aHeader))
            {
                qDebug()<<QString("Data6aHeader length error! len = %1 [%2]").arg(len).arg(sizeof (Data6aHeader));
                continue;
            }

            Data6aHeader data6a;
            memcpy(&data6a,data,len);

            //lkj
            QByteArray arr2 = i->value(10).toByteArray();
            char* data2 = arr2.data();
            int len2 = arr2.length();
            string str2 = strhex((unsigned char*)data2,len2);
            qDebug()<<"len2="<<len2<<"\n[[["<<QString::fromStdString(str2);
            if(len2 != sizeof (LDPCRWCC_JCAQXXBW))
            {
                qDebug()<<QString("Data6aHeader length error! len2 = %1 [%2]").arg(len2).arg(sizeof (LDPCRWCC_JCAQXXBW));
                Sleep(10*1000);
                continue;
            }

            LDPCRWCC_JCAQXXBW datalkj;
            memcpy(&datalkj,data2,len2);

            //tcms
            QByteArray arr3 = i->value(11).toByteArray();
            char* data3 = arr3.data();
            int len3 = arr3.length();
            string str3 = strhex((unsigned char*)data3,len);
            qDebug()<<"len3="<<len3<<"\n[[["<<QString::fromStdString(str3);
            if(len3 != sizeof (LIG_INFO_2_0))
            {
                qDebug()<<QString("Data6aHeader length error! len3 = %1 [%2]").arg(len3).arg(sizeof (LIG_INFO_2_0));
                Sleep(10*1000);
                continue;
            }

            LIG_INFO_2_0 datalig;
            memcpy(&datalig,data3,len3);

            rtdw->showData(data6a);
            rtdw->showData(datalkj);
            rtdw->showData(datalig);
        }


        db.disconnect();
        Sleep(10*1000);
    }



}

void RealTimeDataWidget::showData(Data6aHeader data)
{
    //model_lkj_zhidong->;()

    //制动
    QList<QStandardItem*> itemlist;
    for(int i=0;i<18;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_zhidong->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    int n=0;
    itemlist.value(n++)->setText("停放制动异常施加：");
    itemlist.value(n++)->setText(data.ab1.ab1bw.alt & 0x01?"是":"否");
    itemlist.value(n++)->setText("列车贯通辆数:");
    itemlist.value(n++)->setText(QString("%1").arg(data.ab1.ab1bw.cnt)     );//    <<"列车贯通辆数"    //       byte	cnt;		// 列车贯通辆数，255表示无效
    itemlist.value(n++)->setText("停放制动异常缓解：");
    itemlist.value(n++)->setText("");
    itemlist.value(n++)->setText("折关子板通信故障：");
    itemlist.value(n++)->setText("");
    itemlist.value(n++)->setText("列车管压力：");
    itemlist.value(n++)->setText((short)data.ab1.ab1bw.lcg ==-1?"故障":QString("%1").arg(data.ab1.ab1bw.lcg)     );//    <<"列车管压力（kPa）"      //       unsigned short	lcg;		// 列车管压力（kPa）	-1为故障
    itemlist.value(n++)->setText("停放缸压力：");
    itemlist.value(n++)->setText((short)data.ab1.ab1bw.tfg ==-1?"故障":QString("%1").arg(data.ab1.ab1bw.tfg)     );//    <<"停放缸压力（kPa）"      //       unsigned short	tfg;		// 停放缸压力（kPa）	-1为故障
    itemlist.value(n++)->setText("均衡缸压力：");
    itemlist.value(n++)->setText((short)data.ab1.ab1bw.jhg ==-1?"故障":QString("%1").arg(data.ab1.ab1bw.jhg)     );//    <<"均衡缸压力（kPa）"      //       unsigned short	jhg;		// 均衡缸压力（kPa）	-1为故障
    itemlist.value(n++)->setText("列车管流量：");
    itemlist.value(n++)->setText((short)data.ab1.ab1bw.llj ==-1?"故障":QString("%1").arg(data.ab1.ab1bw.llj)     );//    <<"列车管流量"            //       unsigned short	llj;		// 列车管流量			-1为故障
    itemlist.value(n++)->setText("运行速度：");
    itemlist.value(n++)->setText((short)data.ab1.ab1bw.speed ==-1?"故障":QString("%1").arg(data.ab1.ab1bw.speed)   );//    <<"运行速度（km/h）";     //       unsigned short	speed;		// 运行速度（km/h）

    //防火
    itemlist.clear();
    for(int i=0;i<132;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_fanghuo->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("防火总线开路：");
    itemlist.value(n++)->setText(data.af1.ab1bw.zxkl ==1?"是":"否");
    itemlist.value(n++)->setText("防火总线短路：");
    itemlist.value(n++)->setText(data.af1.ab1bw.zxdl ==1?"是":"否");
    for(int i=0;i<32;i++)
    {
        itemlist.value(n++)->setText(QString("%1号探头报警码").arg(i+1));
        switch (data.af1.ab1bw.alt[i]) {
        case 1:
            itemlist.value(n++)->setText("报警");
            break;
        case 2:
            itemlist.value(n++)->setText("故障");
            break;
        case 3:
            itemlist.value(n++)->setText("污染");
            break;
        case 4:
            itemlist.value(n++)->setText("隔离");
            break;
        default:
            itemlist.value(n++)->setText("正常");
            break;
        }
        itemlist.value(n++)->setText(QString("%1号探头类型码").arg(i+1));
        switch (data.af1.ab1bw.sen[i]) {
        case 1:
            itemlist.value(n++)->setText("报警");
            break;
        case 2:
            itemlist.value(n++)->setText("故障");
            break;
        case 3:
            itemlist.value(n++)->setText("污染");
            break;
        case 4:
            itemlist.value(n++)->setText("隔离");
            break;
        default:
            itemlist.value(n++)->setText("正常");
            break;
        }
    }


    //走行
    for(int i=0;i<6;i++) //1~6轴
    {
        //温度表
        for(int j=0;j<6;j++)// 1-8位温度值（℃） 127-传感器故障
        {
            QStandardItem* item =new QStandardItem(data.at1[i].ab1bw.tmp[j]==127?"传感器故障":QString::number(data.at1[i].ab1bw.tmp[j]));
            item->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
            model_6A_zouxing[0]->setItem(i,j,item);
        }

        model_6A_zouxing[0]->setItem(i,6,new QStandardItem(QString::number(data.at1[i].ab1bw.hw1)));
        model_6A_zouxing[0]->setItem(i,7,new QStandardItem(QString::number(data.at1[i].ab1bw.hw2)));

        //轴报警
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<8;k++)
            {
                QStandardItem* item = new QStandardItem((data.at1[i].ab1bw.alt[j]>>k & 1)==1?"报警":"√");
                item->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
                model_6A_zouxing[i+1]->setItem(j,k,item);
            }
        }
    }


    //视频
        //状态
    itemlist.clear();
    for(int i=0;i<6;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_shipin[0]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("采集卡1状态：");
    itemlist.value(n++)->setText(data.av3.ab1bw.cjk1 ==1?"故障":"正常");
    itemlist.value(n++)->setText("采集卡2状态：");
    itemlist.value(n++)->setText(data.av3.ab1bw.cjk2 ==1?"故障":"正常");
    itemlist.value(n++)->setText("存储卡状态：");
    itemlist.value(n++)->setText(data.av3.ab1bw.disk ==1?"故障":"正常");

        //通道
    for (int i=0;i<16;i++) {
        model_6A_shipin[1]->setItem(0,i,new QStandardItem("--"));
        model_6A_shipin[1]->setItem(1,i,new QStandardItem(data.av3.ab1bw.chn[i]==1?"故障":"√"));
        model_6A_shipin[1]->setItem(2,i,new QStandardItem("无效"));
    }



    //版本
    itemlist.clear();
    for(int i=0;i<2;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_banben->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("6A软件版本：");
    itemlist.value(n++)->setText("--");


    //瞭望
    itemlist.clear();
    for(int i=0;i<12;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_liaowang->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("1端图像采集器：");
    itemlist.value(n++)->setText((data.av4.ab1bw.err>>0 & 1) == 1 ? "故障":"--");
    itemlist.value(n++)->setText("2端图像采集器：");
    itemlist.value(n++)->setText((data.av4.ab1bw.err>>1 & 1) == 1 ? "故障":"--");
    itemlist.value(n++)->setText("板卡自检：");
    itemlist.value(n++)->setText((data.av4.ab1bw.err>>2 & 1) == 1 ? "故障":"--");
    itemlist.value(n++)->setText("瞭望提醒：");
    itemlist.value(n++)->setText(data.av4.ab1bw.sta>0&&data.av4.ab1bw.sta<4 ? QString("%1级瞭望提醒").arg(data.av4.ab1bw.sta):"--");
    itemlist.value(n++)->setText("一端摄像头启用：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("二端摄像头启用：");
    itemlist.value(n++)->setText("--");



    //油位
    itemlist.clear();
    for(int i=0;i<4;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_youwei->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("油量：");
    itemlist.value(n++)->setText(QString::number(data.yw1.ab1bw.yl));
    itemlist.value(n++)->setText("油位：");
    itemlist.value(n++)->setText(QString::number(data.yw1.ab1bw.yw));

    //平台
    itemlist.clear();
    for(int i=0;i<20;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_6A_pingtai->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("CPU主控角色：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("ST卡状态：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("轴温安全环报警：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("防火安全环报警：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("轴温安全环离线：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("防火安全环离线：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("轴温安全环继电器状态：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("防火安全环继电器状态：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("轴温安全环隔离状态：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("防火安全环隔离状态：");
    itemlist.value(n++)->setText("--");

    itemlist.clear();
}

void RealTimeDataWidget::showData(LDPCRWCC_JCAQXXBW data)
{
    //制动
    QList<QStandardItem*> itemlist;
    for(int i=0;i<70;i++)
    {
        QStandardItem *item =std::make_unique<QStandardItem>().get();
        itemlist.push_back(item);
        model_lkj->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    int n=0;
    itemlist.value(n++)->setText("机车：");
    itemlist.value(n++)->setText(QString("HXN5-%1").arg(data.EngineNo,4,10,QChar('0')));
    itemlist.value(n++)->setText("车次:");

    itemlist.value(n++)->setText(QString("%1%2").arg(QString::fromStdString((char*)data.Trainzm)).arg(data.Trainsz));//    <<"列车贯通辆数"    //       byte	cnt;		// 列车贯通辆数，255表示无效
    itemlist.value(n++)->setText("司机：");
    itemlist.value(n++)->setText(QString::number(data.DriverNo));
    itemlist.value(n++)->setText("副班/学习司机：");
    itemlist.value(n++)->setText(QString::number(data.CopilotNo));
    itemlist.value(n++)->setText("司机联系方式：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("副班司机联系方式：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("交路号：");
    itemlist.value(n++)->setText(QString::number(data.FactRoute));
    itemlist.value(n++)->setText("前方交路号：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("车站(TMIS)：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("车站(LKJ)：");
    itemlist.value(n++)->setText(QString::number(data.stationNo));
    itemlist.value(n++)->setText("前方车站(TMIS)：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("前方车站(LKJ)：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("当前线路号标志：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("当前线路号：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("前方线路号标志：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("前方线路号：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("客货/本补：");
    itemlist.value(n++)->setText(QString::number(data.TrainFlag));
    itemlist.value(n++)->setText("输入交路号：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("限速：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("速度：");
    itemlist.value(n++)->setText(QString::number(data.TSpeed));
    itemlist.value(n++)->setText("机车工况：");
    itemlist.value(n++)->setText(QString::number(data.TrainState));
    itemlist.value(n++)->setText("机车运行方向：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("零位：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("监控状态：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("机车信号：");
    itemlist.value(n++)->setText(QString::number(data.TrainSign));
    itemlist.value(n++)->setText("公里标：");
    itemlist.value(n++)->setText(QString::number(data.stationNo));
    itemlist.value(n++)->setText("信号机种类：");
    itemlist.value(n++)->setText(QString::number(data.stationNo));
    itemlist.value(n++)->setText("信号机编号：");
    itemlist.value(n++)->setText(QString::number(data.SignNo));
    itemlist.value(n++)->setText("距离前方信号机：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("制动输出：");
    itemlist.value(n++)->setText("--");
    itemlist.value(n++)->setText("总重：");
    itemlist.value(n++)->setText(QString::number(data.CarWeight));
    itemlist.value(n++)->setText("计长：");
    itemlist.value(n++)->setText(QString::number(data.CarLong));
    itemlist.value(n++)->setText("辆数：");
    itemlist.value(n++)->setText(QString::number(data.CarCount));
    itemlist.value(n++)->setText("列车管压力：");
    itemlist.value(n++)->setText(QString::number(data.PipePressure));

    itemlist.clear();

}

QString swc(unsigned char chr, const QString &str)
{
    //格式 0=a,1=b,3=c
    QString ss;

    bool ok=false;//找到chr没有的标志
    for(auto i=str.begin();i<str.end();i++)
    {
        if(*i >= '0' && *i <= '9')
        {
            ss+=*i;
        }
        else if( *i == '=')
        {
            if(ss.toInt()==chr)//找到了
            {
                ok=true;
                ss.clear();
                bool space=0;
                for(++i;i<str.end() && *i != ',' ;i++)
                {
                    if(space==0 && *i == ' ')
                    {
                        continue;
                    }
                    ss+=*i;
                    space=1;
                }
                return ss;
            }
            else
            {
                ss.clear();
            }
        }
        else
        {
            if(*i!=' ')
            {
                ss.clear();
            }
        }

    }

    return QString("[%1]").arg(chr);
}


QString swc(unsigned char chr, int num, const QString &str)
{
    //格式 0=a,1=b,3=c
    QString ss;
    chr = (chr>>num) & 0x01;

    bool ok=false;//找到chr没有的标志
    for(auto i=str.begin();i<str.end();i++)
    {
        if(*i >= '0' && *i <= '9')
        {
            ss+=*i;
        }
        else if( *i == '=')
        {
            if(ss.toInt()==chr)//找到了
            {
                ok=true;
                ss.clear();
                bool space=0;
                for(++i;i<str.end() && *i != ',' ;i++)
                {
                    if(space==0 && *i == ' ')
                    {
                        continue;
                    }
                    ss+=*i;
                    space=1;
                }
                return ss;
            }
            else
            {
                ss.clear();
            }
        }
        else
        {
            if(*i!=' ')
            {
                ss.clear();
            }
        }

    }

    return QString("[%1]").arg(chr);
}

QString swc_bit(unsigned char chr, const QString &str)
{
    //格式 0=a,1=b,3=c
    QString tmp,ss;

    bool ok=false;//找到chr没有的标志
    for(auto i=str.begin();i<str.end();i++)
    {
        if(*i >= '0' && *i <= '9')
        {
            ss+=*i;
        }
        else if( *i == '=')
        {
            if(((chr>>ss.toInt()) & 1))//找到了
            {
                ok=true;
                //qDebug()<<"数字ss"<<ss;
                ss.clear();
                bool space=0;
                for(++i;i<str.end() && *i != ',' ;i++)
                {
                    if(space==0 && *i == ' ')
                    {
                        continue;
                    }
                    ss+=*i;
                    space=1;
                }
                tmp=tmp+ss+" ";
                ss.clear();
            }
            else
            {
                ss.clear();
            }
        }
        else
        {
            if(*i!=' ')
            {
                ss.clear();
            }
        }

    }

    if(tmp.length()<1)
    {
        tmp="正常";
    }
    return tmp;
}

void RealTimeDataWidget::showData(LIG_INFO_2_0 data)
{
    //基本运行信息
    QList<QStandardItem*> itemlist;
    for(int i=0;i<60;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_tcms[0]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    int n=0;
    itemlist.value(n++)->setText("警惕重置：");itemlist.value(n++)->setText(data.AlerterReset?"是":"否");
    itemlist.value(n++)->setText("警惕报警：");itemlist.value(n++)->setText(data.AlerterAlarm?"是":"否");
    itemlist.value(n++)->setText("警惕切除：");itemlist.value(n++)->setText(data.AlerterCutout?"是":"否");
    itemlist.value(n++)->setText("自动制动手柄位置：");itemlist.value(n++)->setText(swc(data.AutomaticBrakeHandlePos, "0 = 制动区,"
                                                                                                         "1 = 抑制,"
                                                                                                         "2 = 缓解,"
                                                                                                         "3 = 其他,"
                                                                                                         "4 = 紧急"));
    itemlist.value(n++)->setText("单独缓解：");itemlist.value(n++)->setText(data.BailOffNCommand?"Bail":"No Bail");
    itemlist.value(n++)->setText("车长阀紧急：");itemlist.value(n++)->setText(data.ConductorValveEmergency?"Applied":"Not Applied");


    //柴油机系统数据
    itemlist.clear();
    for(int i=0;i<60;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_tcms[1]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("警惕重置：");itemlist.value(n++)->setText(data.AlerterReset?"是":"否");


    //牵引系统
    itemlist.clear();
    for(int i=0;i<60;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_tcms[2]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("警惕重置：：");
    itemlist.value(n++)->setText(data.AlerterReset?"Yes":"No");


    //辅助系统
    itemlist.clear();
    for(int i=0;i<60;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_tcms[2]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("警惕重置：：");
    itemlist.value(n++)->setText(data.AlerterReset?"Yes":"No");


    //制动控制系统
    itemlist.clear();
    for(int i=0;i<60;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_tcms[2]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("警惕重置：：");
    itemlist.value(n++)->setText(data.AlerterReset?"Yes":"No");


    //版本与累计信息数据
    itemlist.clear();
    for(int i=0;i<60;i++)
    {
        QStandardItem *item =new QStandardItem;
        itemlist.push_back(item);
        model_tcms[2]->setItem(i/4,i%4,item);
        if(i%2==0)
        {
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            item->setBackground(QBrush(RGB(234,239,240)));
        }
    }
    n=0;
    itemlist.value(n++)->setText("警惕重置：：");
    itemlist.value(n++)->setText(data.AlerterReset?"Yes":"No");

}



void RealTimeDataWidget::start(int trainNo)
{
    startGetData=true;
    currentQuerytrainNo=trainNo;
    qDebug()<<"query train "<<trainNo;
}

void RealTimeDataWidget::on_pushButton_1zhou_clicked()
{
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[1]);
}

void RealTimeDataWidget::on_pushButton_2zhou_clicked()
{
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[2]);
}

void RealTimeDataWidget::on_pushButton_3zhou_clicked()
{
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[3]);
}

void RealTimeDataWidget::on_pushButton_4zhou_clicked()
{
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[4]);
}

void RealTimeDataWidget::on_pushButton_5zhou_clicked()
{
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[5]);
}

void RealTimeDataWidget::on_pushButton_6zhou_clicked()
{
    ui->tableView_rt_zouxing_zbj->setModel(model_6A_zouxing[6]);
}
