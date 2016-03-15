#include "signup.h"
#include "ui_signup.h"
#include "QFile"
#include "QTextStream"
#include "mainwindow.h"
#include<QDebug>
#include<QMessageBox>
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setWindowTitle("SIGNUP");

    QPixmap pix("D:\\qt\\irctc3\\logo.jpg");
    ui->label_4->setPixmap(pix);
}

signup::~signup()
{
    delete ui;
}

void signup :: open_login()
{
    log=new login(this);
    log->show();
}

QString signup:: encrypted(QString pass)
{
    int n=pass.length();
    int i;
    std::string s=pass.toUtf8().constData();
    for(i=0;i<n;i++)
    {
        if(s[i]=='y')
            s[i]='a';
        if(s[i]=='Y')
            s[i]='A';
        if(s[i]=='z')
            s[i]='b';
        if(s[i]=='Z')
            s[i]='B';
        else
        s[i]=s[i]+2;
    }
    pass=QString ::fromStdString(s);
    return pass;
}

void signup::on_buttonBox_accepted()
{
    QString name,pass,mobile;
    name=ui->lineEdit->text();
    pass=ui->lineEdit_2->text();
    mobile=ui->lineEdit_3->text().toInt();
    if(name=="" || pass=="")
    {
         QMessageBox::critical(this,tr("error"),tr("fields are empty"));
    }
    else
    {
    pass=encrypted(pass);
    QString filename="D:\\qt\\irctc3\\user.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "NO exist "<<filename;
    }else{
        qDebug() << filename<<" exits...";
    }
    QTextStream out(&file);
    file.open(QFile::ReadWrite | QFile::Append);
    out<<"\n"<<name<<" ";
    out<<pass<<" ";
    file.close();
    this->hide();
    open_login();
    }
}

void signup::on_buttonBox_rejected()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void signup::on_pushButton_clicked()
{
    exit(0);
}
