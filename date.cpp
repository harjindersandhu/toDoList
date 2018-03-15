#include "date.h"
#include "activity.h"
#include "list.h"
#include <iostream>
#include "QDate"


Date::Date(){

}

Date::Date(int y, int m, int d) {
    int i = 0;

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){  // controllo sull'anno bisestile
        i = 1;
    }

    year = y;
    month = m;
    day = d;

}

Date::Date(const Date& orig) {
}

bool Date::checkDate(){
    int i = 0;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){  // controllo sull'anno bisestile
        i = 1;
    }
    if (month>12){
        return false;
    } else {
        switch(month){
            case (1):
            case (3):
            case (5):
            case (7):
            case (8):
            case (10):
            case (12):
            if(day>=31){
            return false;
            break;
            }
            case (2):
                if(day>=28+i){
                    return false;
                    break;
                }
            case (4):
            case (6):
            case (9):
            case (11):
                if(day>=30){
                return false;
                break;
                }
        }
    }
}

int Date::compareDate(Date d){
    if(year==d.getYear()){
        if(month==d.getMonth()){

            if(day==d.getDay()){
                return 0; // ritorna 0 se i due giorni coincidono
            }
            if(day>d.getDay()){
                return -1; // giorno già passato
            }
            if(day<=d.getDay()){
                return 1; // giorno non ancora passato
            }
        }
        else{
            if(month>=d.getMonth()){
                return -1; // giorno già passato
            }
            if(month<=d.getMonth()){
                return 1;   // giorno non ancora passato
            }
        }
    }
    else{
            if(year>=d.getYear()){
                return -1; // giorno già passato
            }
            if(year<=d.getYear()){
                return 1;  // giorno non ancora passato
            }
        }
}





