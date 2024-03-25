#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <iostream>
#include <fstream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   QString myString;
    const int len = 2832, strings =1737;
    const char ch = '\n';
    char mass[len][strings];
    
    ifstream fs("/mnt/247E7EDA7E7EA3E8/книги/загрузки_Яндекс_браузера/единицы/единицы из шрифтов/black-white/отобранные/список.txt", ios::in | ios::binary);
    
    QString comanda1="magick \"/mnt/247E7EDA7E7EA3E8/книги/загрузки_Яндекс_браузера/единицы/единицы из шрифтов/black-white/отобранные/обрез_снизу/";    
      QString font;
    QString comanda3="\" -gravity South \  -background white -splice 0x1  -background black -splice 0x1 \  -trim  +repage -chop 0x1   \"/mnt/247E7EDA7E7EA3E8/книги/загрузки_Яндекс_браузера/единицы/единицы из шрифтов/black-white/отобранные/полный_обрез/";
    QString comanda4="\"";
    QString comanda_vsia;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    for(int r = 0; r<strings; r++)
    {
        fs.getline(mass[r], len-1,ch); //Считываем строки в массив
        
        font=mass[r];
        // subString = myString.mid(7,myString.size() - 1);
        comanda_vsia=comanda1+font+comanda3+font+comanda4;
        system (comanda_vsia.toStdString().c_str() );
        
    }
    
    fs.close(); //Закрываем файл   
}

Dialog::~Dialog()
{
    delete ui;
}

