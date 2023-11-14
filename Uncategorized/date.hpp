# include "templete.hpp"

/*1年1月1日からの経過日数(1年1月1日が0日目)*/
int days(int y,int m,int d){
    if(m==1||m==2){
        m+=12;
        y--;
    }
    return 365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;
}

/*曜日計算*/
int wday(int y,int m,int d){
    if(m==1||m==2){
        m+=12;
        y--;
    }
    return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;
    //0,1,2,...日,月,火
}

