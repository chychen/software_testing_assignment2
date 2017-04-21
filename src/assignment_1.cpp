#include "assignment_1.h"

using namespace std;

string Triangle(int a, int b, int c){
    // value validation
    bool isValid = true;
    string invalidEdges = "";
    if(1>a||a>200){
        isValid = false;
        invalidEdges = invalidEdges + "a";
    }
    if(1>b||b>200){
        isValid = false;
        if(invalidEdges==""){
            invalidEdges = invalidEdges + "b";
        }else{
            invalidEdges = invalidEdges + ", b";
        }
    }
    if(1>c||c>200){
        isValid = false;
        if(invalidEdges==""){
            invalidEdges = invalidEdges + "c";
        }else{
            invalidEdges = invalidEdges + ", c";
        }
    }
    if(!isValid){
        return "Value if " + invalidEdges + " is not in the range of permitted values";
    }
    // Is A Triangle?
    if(a<b+c && b<a+c && c<b+c){// Yes
        unsigned type = 0;
        if(a==b)type++;
        if(b==c)type++;
        if(c==a)type++;
        // Determine Triangle Type
        switch(type){
            case 3:
                return "Equilateral";
            case 2:
                //no specific name
            case 1:
                return "Isosceles";
            default:
                return "Scalene";
        }
    }else{// No
        return "Not a triangle";
    }
}

bool isLeapYear(int year){
    if (year%4!=0)return false;
    else if (year%100!=0) return true;
    else if (year%400!=0) return false;
    else return true;
}

string NextDate(int month, int day, int year){
    bool isValid = true;
    string validMsg = "";
    if(month<1 || month>12){
        isValid = false;
        validMsg = validMsg + "month not in 1...12";
    } 
    if(day<1 || day>31){
        isValid = false;
        if(validMsg!="") validMsg = validMsg + "\nday not in 1...31";
        else validMsg = validMsg + "day not in 1...31";
    }
    if(year<1812 || year>2012){
        isValid = false;
        if(validMsg!="") validMsg = validMsg + "\nyear not in 1812...2012";
        else validMsg = validMsg + "year not in 1812...2012";
    }
    
    if(!isValid){
        return validMsg;
    }else{
        int tomorrowMonth=month, tomorrowDay=day, tomorrowYear=year;
        if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10){
            if (day<31){
                tomorrowDay = day + 1;
            }else if (day==31){
                tomorrowDay = 1;
                tomorrowMonth = month + 1;
            }else{
                return "Invalid input date";
            }
        }else if (month==4 || month==6 || month==9 || month==11){
            if (day<30){
                tomorrowDay = day + 1;
            }else if (day==30){
                tomorrowDay = 1;
                tomorrowMonth = month + 1;
            }else{
                return "Invalid input date";
            }
        }else if (month==12){
            if (day<31){
                tomorrowDay = day + 1;
            }else if (day==31){
                tomorrowDay = 1;
                tomorrowMonth = 1;
                if (year==2012){
                    return "2012 is over";
                }else{
                    tomorrowYear = year + 1;
                }
            }else{
                return "Invalid input date";
            }
        }else if (month==2){
            if (day<28){
                tomorrowDay = day + 1;
            }else if (day==28){
                if (isLeapYear(year)){
                    tomorrowDay = 29;
                }else{
                    tomorrowDay = 1;
                    tomorrowMonth = 3;
                }
            }else if (day==29){
                if (isLeapYear(year)){
                    tomorrowDay = 1;
                    tomorrowMonth = 3;
                }else{
                    return "Invalid input date";
                }
            }else{
                return "Invalid input date";
            }
        }
        return to_string(tomorrowMonth) + "/" + to_string(tomorrowDay) + "/" + to_string(tomorrowYear);
    }
}

string Commission(int locks, int stocks, int barrels){
    
    if(locks==-1)return "Program terminates";

    int lockPrice, stockPrice, barrelPrice;
    int totalLocks, totalStocks, totalBarrels;
    int lockSales, stockSales, barrelSales;
    int sales, commission;
    lockPrice = 45;
    stockPrice = 30;
    barrelPrice = 25;
    totalLocks = 0;
    totalStocks = 0;
    totalBarrels = 0;

    bool isValid = true;
    string validMsg = "";

    if(locks<1 || locks>70){
        isValid = false;
        validMsg = validMsg + "locks not in 1...70";
    } 
    if(stocks<1 || stocks>80){
        isValid = false;
        if(validMsg!="") validMsg = validMsg + "\nstocks not in 1...80";
        else validMsg = validMsg + "stocks not in 1...80";
    }
    if(barrels<1 || barrels>90){
        isValid = false;
        if(validMsg!="") validMsg = validMsg + "\nbarrels not in 1...90";
        else validMsg = validMsg + "barrels not in 1...90";
    }
    
    if(!isValid){
        return validMsg;
    }else{
        totalLocks += locks;
        totalStocks += stocks;
        totalBarrels += barrels;

        lockSales = lockPrice * totalLocks;
        stockSales = stockPrice * totalStocks;
        barrelSales = barrelPrice * totalBarrels;
        sales = lockSales + stockSales + barrelSales;
        
        if(sales>1800.0){
            commission = 0.10 * 1000.0;
            commission += 0.15 * 800.0;
            commission += 0.2 * (sales-1800.0);
        }else if(sales>1000.0){
            commission = 0.10 * 1000.0;
            commission += 0.15 * (sales-1000.0);
        }else{
            commission = 0.10 * sales;            
        }
        return "$" + to_string(commission);
    }


}