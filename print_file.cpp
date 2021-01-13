#include "print_file.h"
#include <QPrintDialog>
static QString  single_seva;
static int  single_cost;
static QString single_tickets;
static QString single_sevadate;

print_file::print_file(QWidget *parent) : QWidget(parent)
{
    list_seva = new QList<QString>;
    list_cost = new QList<float>;
    list_tickets = new QList<QString>;
    list_sevadate = new QList<QString>;
    voc_purpose = new QList<QString>;
    voc_cat = new QList<QString>;
    voc_pri = new QList<float>;
    newfile = QString("/home/avinash/TEMPLE.txt");
    file.setFileName(newfile);
    svg_file = QString("/home/avinash/fawnright.svg");
    //qDebug()<<Q_FUNC_INFO<<"____________________++++++++++++++++++++++++++_______________________"<<endl;

}

int print_file::write2file(QString seva_S,QString name_S,QString gothram_S,QString nakshatram_S,float cost_S,QString date_S)
{
    /*-------SAVING PRINTABLE DATA INTO FILE OF PERSON-------*/

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream<<"****"<<seva_S<<"****"<<endl;
        stream<<"Name     ::  "<<name_S<<endl;
        stream<<"gothram  ::  "<<gothram_S<<endl;
        stream<<"Nakshatram:: "<<nakshatram_S<<endl;
        stream<<"price     :: "<<cost_S<<endl;
        stream<<"Date      :: "<<date_S<<endl;
        qDebug()<<"data entering into file"<<endl;
    }
    return 0;
}
void print_file::PrinterPreview()
{
    /*-------PREVIEW OF THE PRINTER----------*/
}

int print_file::printing_file(QList<Print_Detail> *pd)
{
    QPrinter printer;
    qDebug()<<"in";
    printer.setOrientation(QPrinter::Portrait);
    QPainter painter;
    QPrintDialog *dlg = new QPrintDialog(&printer);
    dlg->exec();
    {
        if (! painter.begin(&printer))
        {
            qWarning("failed to open file, is it writable?");
        }
        painter.setPen(Qt::black);

        unsigned short left_margin=225, top_margin=10, rect_width = 550;
        painter.drawRect(left_margin, top_margin, 370,360);

        painter.setFont(QFont("Times New Roman", 8.5, QFont::Bold));
        painter.drawText(left_margin+10,top_margin+20,"SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST");
        painter.setFont(QFont("Times New Roman",7));
        painter.drawText(left_margin+15,top_margin+40,"Survey No.8, Sri Raghavendraswamy Matha Road, 9th Main, 3rd Stage BEML Layout");
        painter.setFont(QFont("Times New Roman",7.5));
        painter.drawText(left_margin+120,top_margin+60,"RR Nagar,   Bengaluru- 560098");
        painter.setFont(QFont("Times New Roman", 8, QFont::Bold));
        painter.drawText(left_margin+13,top_margin+80,"Ph:080-41206779      Office Timings: 8AM to 1PM & 6PM to 8.30PM");

        QLineF line1(left_margin,top_margin+90,rect_width+45,100);
        painter.drawLine(line1);
        painter.setFont(QFont("Arial",8));
        painter.drawText(left_margin+10,top_margin+105,"Name:");
        painter.drawText(left_margin+60,top_margin+105,pd->front().NAME);
        QLineF line10(left_margin,top_margin+115,rect_width+45,125);
        painter.drawLine(line10);

        painter.drawText(left_margin+10,top_margin+130,"Mob. No:");
        painter.drawText(left_margin+70,140,pd->front().MOB_NO);
        QLineF line11(left_margin,top_margin+140,rect_width+45,150);
        painter.drawLine(line11);

        painter.drawText(left_margin+10,top_margin+155,"Gothra:");
        painter.drawText(left_margin+70,top_margin+155,pd->front().GOTHRA);
        QLineF line12(left_margin,top_margin+165,rect_width+45,175);
        painter.drawLine(line12);

        painter.drawText(left_margin+10,top_margin+180,"Nakshatra:");
        painter.drawText(left_margin+75,top_margin+180,pd->front().NAKSHATRA);

        QLineF line4(left_margin+160,top_margin+90,left_margin+160,200);
        painter.drawLine(line4);

        painter.drawText(left_margin+185,top_margin+105,"Recpt.no:");
        painter.drawText(left_margin+250,top_margin+105,pd->front().RECPT_NO);

        qDebug()<<"s_date:"<<s_date<<endl;

        painter.drawText(left_margin+185,top_margin+130,"Date:");
        s_date =QString(current_date.currentDate().toString());
        painter.drawText(left_margin+250,top_margin+130,s_date);

        painter.drawText(left_margin+185,top_margin+155,"Seva Date:");
        painter.drawText(left_margin+250,top_margin+155,pd->back().SEVA_DATE);

        painter.drawText(left_margin+185,top_margin+180,"Seva Time:");
        painter.drawText(left_margin+250,top_margin+180,pd->back().SEVA_TIME);

        QLineF line2(left_margin,top_margin+190,rect_width+45,200);
        painter.drawLine(line2);
        painter.drawText(left_margin+5,top_margin+205,"Sl.no");
        painter.drawText(left_margin+55,top_margin+205,"Seva Name");
        painter.drawText(left_margin+220,top_margin+205,"Cost");

        painter.drawText(left_margin+265,top_margin+205,"Persons");
        painter.drawText(left_margin+322,top_margin+205,"Amount");
        QLineF line9(left_margin,top_margin+215,rect_width+45,225);
        painter.drawLine(line9);

        int next_slot_y = top_margin+215, next_slot_x = left_margin+5;

        for(int i = 0; i < pd->size();i++)
        {
            next_slot_y = next_slot_y + 20;
            painter.drawText(next_slot_x,next_slot_y, QString::number(i+1));
            painter.drawText(next_slot_x+30,next_slot_y,pd->at(i).SEVA_DESCR);
            painter.drawText(next_slot_x+210,next_slot_y,pd->at(i).RATE);
            painter.drawText(next_slot_x+270,next_slot_y,pd->at(i).QTY);

            QRectF amt_rect(next_slot_x-275,next_slot_y-13,rect_width-left_margin+309,20);
            painter.drawText(amt_rect, Qt::AlignRight, pd->at(i).AMT+".00");

            //painter.drawText(next_slot_x+308,next_slot_y,pd->at(i).AMT+".00");
            //qDebug()<<"\n++++++++++++++++Amount is +++++++++++++"<<pd->at(i).AMT<<endl<<endl;

        }
        QLineF line3(left_margin+260,top_margin+190,left_margin+260,370);
        painter.drawLine(line3);

        QLineF line5(left_margin+309,top_margin+190,left_margin+309,370);
        painter.drawLine(line5);
//        QLineF line6(left_margin+370,top_margin+190,left_margin+370,370);
//        painter.drawLine(line6);

        painter.setFont(QFont("Arial",7.5));

        painter.drawText(left_margin+285,top_margin+370," Total: ₹ ");
        painter.setFont(QFont("Times New Roman", 8, QFont::Bold));
        painter.drawText(left_margin+327,top_margin+370,pd->back().TOTAL_AMT+".00");

        painter.setFont(QFont("Arial",7.5));

        painter.drawText(left_margin,top_margin+386,"Total in words:₹");
        painter.drawText(left_margin+70,top_margin+386,pd->back().TOTAL_IN_WORDS+" only");

        //painter.setFont(QFont("Arial",7));

        painter.drawText(left_margin+2,top_margin+405,"Note:");
        painter.drawText(left_margin+37,top_margin+405,pd->back().NOTE);
        //qDebug()<<"\n$$$$$$$$$$$$$$$$$$Total in words: "<<pd->back().TOTAL_IN_WORDS<<endl<<endl;


        QPixmap mypix(":/Rules.jpeg");
        painter.drawPixmap(left_margin,top_margin+412,370,120,mypix);

        //        painter.setFont(QFont("Arial",8));
        //        painter.drawText(20,440,"ನಿಬಂಧನೆಗಳು :- ");
        //        painter.drawText(20,460,"1.ಸೇವಾಕರ್ತರು  ಸೇವಾ ದಿನಾಂಕದಂದು ನಿಗದಿತ ಸಮಯಕ್ಕೆ ಬಂದು ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಿಸಬೇಕು.");
        //        painter.drawText(20,480,"2.ಸೇವಾಕರ್ತರು ಬರದಿದ್ದ/ ತಡಮಾಡಿದ ಪಕ್ಷದಲ್ಲಿ ಅವರ ಹೆಸರಿನಲ್ಲಿ ಸಂಕಲ್ಪ ಮಾಡಿ ಸೇವೆ ಮಾಡಲಾಗುವುದು.");
        //        painter.drawText(20,500,"3.ಸೇವಾಕರ್ತೃಗಳು ಭಾರತೀಯ ಉಡುಪಿನಲ್ಲಿ ಬರುವುದು ಸೂಕ್ತ.");
        //        painter.setFont(QFont("Arial",8,QFont::Bold));
        //        painter.drawText(20,520,"ಮಧ್ವ ಮತದ ಸಿದ್ಧಾಂತದ ಪದ್ಧತಿ ಬಿಡಬ್ಯಾಡಿ, ಬಿಟ್ಟು ಕೆಡಬ್ಯಾಡಿ - ಶ್ರೀ ಪುರಂದರದಾಸರು");

        //qDebug()<<tr(" Rules ")<<endl;
        painter.setFont(QFont("Arial",7.5, QFont::Bold));
        painter.drawText(left_margin+275,top_margin+416,"For SMSR&C Trust");

        if (! printer.newPage())
        {
            qWarning("failed in flushing page to disk, disk full?");
            return 1;
        }
        printer.setPrintRange(QPrinter::CurrentPage);
        painter.end();
    }
    //qDebug()<<"OUT";
}

void print_file::svg_receipt(QString name,QString gothram,QString nakshtram,QString price,QString date,int i,QString tottic,QString totcos,QString con)
{
    //qDebug()<<Q_FUNC_INFO<<"____________________++++++++++++++++++++++++++_______________________"<<endl;

    QSvgGenerator generator;
    generator.setFileName(svg_file);
    QPainter painter;
    {
        if (! painter.begin(&generator))
        {
            qWarning("failed to open file, is it writable?");
        }
        painter.setPen(Qt::black);
        painter.drawRect(7, 7, 1115,400);

        painter.setFont(QFont("Arial", 20));
        painter.drawText(130,30,"SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST");
        painter.setFont(QFont("Arial",14));
        painter.drawText(210,60,"Survey No.8, Sri Raghavendraswamy Mata Road 9th Main 3rd Stage BEML Layout R R Nagar,Bangalore 560098");
        painter.drawText(450,80,"R R Nagar,Bangalore 560098");

        QLineF line1(7,90,1120,90);
        painter.drawLine(line1);
        painter.setFont(QFont("Arial",14));
        painter.drawText(20,110,"Rec.no:");
        QLineF line10(7,115,1120,115);
        painter.drawLine(line10);
        painter.drawText(20,130,"Name:");
        painter.drawText(100,130,name);
        QLineF line11(7,140,1120,140);
        painter.drawLine(line11);


        painter.drawText(20,155,"Mobile:");
        QLineF line12(7,165,1120,165);
        painter.drawLine(line12);
        painter.drawText(100,155,con);
        painter.drawText(20,180,"Seva Date:");
        painter.drawText(100,180,date);
        painter.drawText(420,110,"Date:");

        s_date =QString(current_date.currentDate().toString());
        //qDebug()<<"s_date:"<<s_date<<endl;
        painter.drawText(500,110,s_date);

        painter.drawText(420,130,"Gothram:");
        painter.drawText(500,130,gothram);
        painter.drawText(420,155,"Nakshatram:");
        painter.drawText(500,155,nakshtram);
        painter.drawText(420,180,"Time:");

        QLineF line2(7,190,1120,190);
        painter.drawLine(line2);
        QLineF line9(7,215,1120,215);
        painter.drawLine(line9);
        painter.drawText(15,205,"S.no");
        painter.drawText(100,205,"Description");
        painter.drawText(470,205,"Rate");
        painter.drawText(570,205,"Qty");
        painter.drawText(670,205,"Amount");

        //  -----------------1st seva-------------------------------
        if(i==0)
        {
            painter.drawText(20,225,"1");
            painter.drawText(70,225,single_seva);
            painter.drawText(570,225,single_tickets);
            painter.drawText(470,225,price);
            painter.drawText(335,225,single_sevadate);  //date
            int a = single_tickets.toInt();
            float b = single_cost;
            float c = a*b;
            QString s_c = QString::number(c);
            painter.drawText(670,225,s_c);//cost

        }
        //  -----------------1st addmore seva-------------------------------
        if(i > 1)
        {

            painter.drawText(20,225,"1");
            painter.drawText(70,225,list_seva->at(0));
            painter.drawText(570,225,list_tickets->at(0));
            painter.drawText(335,225,list_sevadate->at(0));   //date
            painter.drawText(470,225,price);                //total = tickets*cost
            float a = list_tickets->at(0).toFloat();
            float b = list_cost->at(0);
            float c = a*b;
            QString s_c = QString::number(c);
            painter.drawText(670,225,s_c);                  //cost
            //qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$<<1>>$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<i<<endl;
        }

        //  /*-----------------2nd addmore seva------------------------------
        if(i > 2)
        {
            painter.drawText(20,245,"2");
            //qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$<<2>>$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<i<<endl;
            painter.drawText(70,245,list_seva->at(1));
            painter.drawText(570,245,list_tickets->at(1));
            painter.drawText(470,245,price);

            painter.drawText(335,245,list_sevadate->at(1));   //date

            float a = list_tickets->at(1).toFloat();
            float b = list_cost->at(1);
            float c = a*b;
            QString s_c = QString::number(c);
            painter.drawText(670,245,s_c);//cost
        }
        //  /*-----------------3rd addmore seva------------------------------
        if(i > 3)
        {
            //qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$<<3>>$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<i<<endl;
            painter.drawText(20,265,"3");
            painter.drawText(70,265,list_seva->at(2));
            painter.drawText(570,265,list_tickets->at(2));
            painter.drawText(470,265,price);

            painter.drawText(335,265,list_sevadate->at(2));   //date

            float a = list_tickets->at(2).toFloat();
            float b = list_cost->at(2);
            float c = a*b;
            QString s_c = QString::number(c);
            painter.drawText(670,265,s_c);//cost
        }
        //  /*-----------------4th addmore seva----------------------------
        if(i > 4)
        {
            //qDebug()<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$<<4>>$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<i<<endl;

            painter.drawText(20,285,"4");
            painter.drawText(70,285,list_seva->at(3));
            painter.drawText(570,285,list_tickets->at(3));
            painter.drawText(470,285,price);

            painter.drawText(335,285,list_sevadate->at(3));   //date

            float a = list_tickets->at(3).toFloat();
            float b = list_cost->at(3);
            float c = a*b;
            QString s_c = QString::number(c);
            painter.drawText(670,285,s_c);//cost
        }
        //  /*-----------------5th  addmore seva----------------------------
        if(i > 5)
        {
            painter.drawText(20,305,"5");
            painter.drawText(70,305,list_seva->at(4));
            painter.drawText(570,305,list_tickets->at(4));
            painter.drawText(470,305,price);

            painter.drawText(335,305,list_sevadate->at(4));   //date

            float a = list_tickets->at(4).toFloat();
            float b = list_cost->at(4);
            float c = a*b;
            QString s_c = QString::number(c);
            painter.drawText(670,305,s_c);//cost
        }

        QLineF line3(7,330,1120,330);
        painter.drawLine(line3);
        painter.drawText(20,350,"Note:");
        painter.drawText(600,390,"Signature");
        painter.setFont(QFont("Arial", 12));
        painter.drawText(50,350,
                         "1.Bring seva receipt at the time of seva. 2.No return and refund of money ");
        painter.drawText(20,380,"paid for seva. 3.Inform your presence before performing seva");
        QLineF line4(400,90,400,190);
        painter.drawLine(line4);

        QLineF line5(550,190,550,380);
        painter.drawLine(line5);
        QLineF line6(650,190,650,380);
        painter.drawLine(line6);
        QLineF line13(450,190,450,380);

        painter.drawLine(line13);
        QLineF line7(450,425,450,400);
        painter.drawLine(line7);


        QLineF line8(55,190,55,330);
        painter.drawLine(line8);

        QLineF line25(330,190,330,330);
        painter.drawLine(line25);
        painter.drawText(360,205,"DATE");


        QLineF line20(450,370,750,370);
        painter.drawLine(line20);

        painter.drawText(462,355,"Total:");
        painter.drawText(565,355,tottic);

        painter.drawText(665,355,totcos);

        //        QLineF line21(550,460,550,460);
        //        painter.drawLine(line21);

        //        QLineF line22(450,460,750,460);
        //        painter.drawLine(line22);


        //           if (! printer.newPage())
        //           {
        //               qWarning("failed in flushing page to disk, disk full?");
        //               return 1;
        //           }
        painter.end();
    }
    //qDebug()<<"OUT";
}


void print_file::svg_voucher(QString id, QString name, QString date, QString mob,int i,QString tot)
{
    QSvgGenerator generator;
    generator.setFileName(svg_file);
    QPainter painter;
    {
        if (! painter.begin(&generator))
        {
            qWarning("failed to open file, is it writable?");
        }
        painter.setPen(Qt::black);
        painter.drawRect(7, 7, 400,550);

        painter.setFont(QFont("Arial", 20));
        painter.drawText(130,45,"SRIMAN MADHVA SANGHA RELIGIOUS AND CHARITABLE TRUST AND CHARITABLE TRUST");
        painter.setFont(QFont("Arial",14));
        painter.drawText(80,75,"Survey No.8, Sri Raghavendraswamy Mata Road 9th Main 3rd Stage BEML Layout");
        painter.drawText(80,85,"R R Nagar,Bangalore 560098");

        QLineF line1(7,90,405,90);
        painter.drawLine(line1);

        painter.setFont(QFont("Arial",14));
        painter.drawText(9,110,"Recepit No");
        painter.setFont(QFont("Arial",14));
        painter.drawText(9,140,"Person Id");
        painter.setFont(QFont("Arial",14));
        painter.drawText(9,170,"Person Name");
        painter.setFont(QFont("Arial",14));
        painter.drawText(9,200,"Mobile No");
        painter.setFont(QFont("Arial",14));
        painter.drawText(9,230,"Date");

        painter.drawText(110,110,":");
        painter.drawText(110,140,":");
        painter.drawText(110,170,":");
        painter.drawText(110,200,":");
        painter.drawText(110,230,":");

        painter.setFont(QFont("Arial",16));
        painter.drawText(120,110,"to add");
        painter.setFont(QFont("Arial",16));
        painter.drawText(120,140,id);
        painter.setFont(QFont("Arial",16));
        painter.drawText(120,170,name);
        painter.setFont(QFont("Arial",16));
        painter.drawText(120,200,date);
        painter.setFont(QFont("Arial",16));
        painter.drawText(120,230,mob);

        QLineF line2(7,240,405,240);
        painter.drawLine(line2);

        painter.drawText(15,260,"Sl.No");
        QLineF line3(55,240,55,470);
        painter.drawLine(line3);

        painter.drawText(70,260,"Purpose");
        QLineF line4(205,240,205,555);
        painter.drawLine(line4);

        painter.drawText(210,260,"Category");
        QLineF line5(335,240,335,510);
        painter.drawLine(line5);

        painter.drawText(340,260,"Price");

        QLineF line10(7,280,405,280);
        painter.drawLine(line10);


        //  -----------------1st -------------------------------
        if(i > -1)
        {
            painter.drawText(30,300,"1");
            painter.drawText(70,300,voc_purpose->at(0));  //purpose
            painter.drawText(210,300,voc_cat->at(0));     //category
            float x1 = voc_pri->at(0);
            QString p1 = QString::number(x1);
            painter.drawText(340,300,p1);              //price
        }
        //  -----------------2nd -------------------------------
        if(i > 0)
        {
            painter.drawText(30,340,"2");
            painter.drawText(70,340,voc_purpose->at(1));  //purpose
            painter.drawText(210,340,voc_cat->at(1));     //category
            float x2 = voc_pri->at(0);
            QString p2 = QString::number(x2);
            painter.drawText(340,340,p2);              //price
        }

        //  -----------------3rd -------------------------------
        if(i > 1)
        {
            painter.drawText(30,380,"3");
            painter.drawText(70,380,voc_purpose->at(2));  //purpose
            painter.drawText(210,380,voc_cat->at(2));     //category
            float x3 = voc_pri->at(0);
            QString p3 = QString::number(x3);
            painter.drawText(340,380,p3);              //price
        }
        //  -----------------4th -------------------------------
        if(i > 2)
        {
            painter.drawText(30,420,"4");
            painter.drawText(70,420,voc_purpose->at(3));  //purpose
            painter.drawText(210,420,voc_cat->at(3));     //category
            float x4 = voc_pri->at(0);
            QString p4 = QString::number(x4);
            painter.drawText(340,420,p4);              //price

        }

        //  -----------------5th -------------------------------
        if(i > 3)
        {
            painter.drawText(30,460,"5");
            painter.drawText(70,460,voc_purpose->at(4));  //purpose
            painter.drawText(210,460,voc_cat->at(4));     //category
            float x5 = voc_pri->at(0);
            QString p5 = QString::number(x5);
            painter.drawText(340,460,p5);              //price
        }
        QLineF line6(7,470,405,470);
        painter.drawLine(line6);

        QLineF line7(7,510,405,510);
        painter.drawLine(line7);
        painter.drawText(240,500,"Total");
        painter.drawText(340,500,tot);

        painter.drawText(240,548,"Manager Signature");

    }
}

void print_file::singleentry(QString devoteSevaName,QString devoteCount,int sevacharge, QString priviusformatdatesevadate)
{
    single_seva = devoteSevaName;
    single_cost=sevacharge;
    single_tickets=devoteCount;
    single_sevadate=priviusformatdatesevadate;
}

void print_file::paintEvent(QPaintEvent *event)
{
    //    QPainter painter(this);
    //    QPixmap mypix(":/Rules.jpeg");
    //    painter.drawPixmap(20,450,600,150,mypix);
}

