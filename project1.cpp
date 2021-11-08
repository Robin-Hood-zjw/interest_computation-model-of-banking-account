#include <iostream>//library
using namespace std;
/*Programmer: JIAWEN ZHANG, Sep. 18  2021( This is the codes for the
first project of EECS402, and the codes try to make two)*/


const int NUM_ONE_MONTH = 1;
const double SMALLEST_BALANCE_CONDITION = 1000.00;
const double LARGEST_BALANCE_CONDITION = 15000.00;
const double SMALLEST_INTEREST_RATE = 0.0015;
const double MEDIUM_INTEREST_RATE = 0.00225;
const double LARGEST_INTEREST_RATE = 0.004;
const int ILLOGICAL_MONTH_NUM_LIMIT = 0;
const double ILLOGICAL_BALANCE_LIMIT = 0.00;
//global constant declarations and initializations here

bool accrueOneMonthsInterest(double &balanceAmt,
                             const bool doPrintInfo
);//prototype of the global function<accrueOneMonthsInteres>
bool accrueInterest(double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth
);//prototype of the global function<accrueInterest>

#ifdef ANDREW_TEST 
#include "andrewTest.h" 
#else 
int main()
{
    double balanceAmt;/*floating number to hint a user's initial balance,
                      and acts as the balance that includes the initial
                      balance and the accrued interest during the specific
                      months*/

    int numMonths;//integer for the month number used in computing

    char inputOfdoPrint;/*result of a user's answer to decide single month's
                        results to show or not*/

    bool doPrint;//results of whether to print each month's results
    
    bool multiMonthsResult;/*result of the balance changes with accrured
                           interest within multiple months*/
    bool oneMonthResult;/*result of the balance and accrued interest gained
                        in one month*/


    cout << "Enter the initial balance of the account: ";
    //Prompt
    cin >> balanceAmt;

    cout << "Enter the number of months to accrue interest: ";
    //Prompt
    cin >> numMonths;

    cout << "Show month-by-month results - 'y' for yes, any other for no: ";
    //Prompt
    cin >> inputOfdoPrint;
    if (inputOfdoPrint != 'y')
    {
        doPrint = false;//Do not print changes in balanceAmit within one month
    }
    else
    {
        doPrint = true;//Print changes in balanceAmit within one month
    }
    
    if(numMonths != NUM_ONE_MONTH)
    {
        multiMonthsResult = accrueInterest(balanceAmt,
                                           numMonths,
                                           doPrint
        );
        /*call the funtion about accuring interest, along with changes in
        BalanceAmt, within months*/
    }
    else
    {
        oneMonthResult = accrueOneMonthsInterest(balanceAmt,
                                                 doPrint
        );
        /*call the funtion for accuring interest, along with changes in
        BalanceAmiy, within one month*/
    }

    return 0;
}
#endif



bool accrueOneMonthsInterest(
 double &balanceAmt,/*balanceAmt is the initial balance and the final
                    balance*/
 const bool doPrintInfo/*false:function performs silently; true:added
                       interest and the balance will be printed*/
 )
 {
     double accuredInterest;//floating number for accrured interest in a month
     double totalInterest;//floating number for the total accured interest
     double initialBalance;/*floating number for the amount of money that will
                           be put into the bank*/

     if (balanceAmt < SMALLEST_BALANCE_CONDITION)
     {
         initialBalance = balanceAmt;/*Initialbalance is equal to balanceAmit
                                     in the case of only one month*/
         accuredInterest = balanceAmt * SMALLEST_INTEREST_RATE;
         balanceAmt += accuredInterest;
         if (doPrintInfo)
         {
             cout << "Accruing interest for 1 month:" << endl;
             cout << "  Initial balance: " << initialBalance << endl;
             cout << "  Initial rate: " << SMALLEST_INTEREST_RATE << endl;
             cout << "  Interest accrued: " << accuredInterest << endl;
             cout << "  New balance: " << balanceAmt << endl;
         }
     }
     else if (balanceAmt >= LARGEST_BALANCE_CONDITION)
     {
         initialBalance = balanceAmt;/*Initialbalance is equal to balanceAmit
                                     in the case of only one month*/
         accuredInterest = balanceAmt * LARGEST_INTEREST_RATE;
         balanceAmt += accuredInterest;
         if (doPrintInfo)
         {
             cout << "Accruing interest for 1 month:" << endl;
             cout << "  Initial balance: " << initialBalance << endl;
             cout << "  Initial rate: " << LARGEST_INTEREST_RATE << endl;
             cout << "  Interest accrued: " << accuredInterest << endl;
             cout << "  New balance: " << balanceAmt << endl;
         }
     }
     else if(balanceAmt >= SMALLEST_BALANCE_CONDITION &&
             balanceAmt < LARGEST_BALANCE_CONDITION)
     {
         initialBalance = balanceAmt;/*Initialbalance is equal to balanceAmit
                                     in the case of only one month*/
         accuredInterest = balanceAmt * MEDIUM_INTEREST_RATE;
         balanceAmt += accuredInterest;
         if (doPrintInfo)
         {
             cout << "Accruing interest for 1 month:" << endl;
             cout << "  Initial balance: " << initialBalance << endl;
             cout << "  Initial rate: " << MEDIUM_INTEREST_RATE << endl;
             cout << "  Interest accrued: " << accuredInterest << endl;
             cout << "  New balance: " << balanceAmt << endl;
         }
     }
     else
     {
         cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0,"
              << " but the value " << balanceAmt << " was provided!" << endl;
         cout << "Sorry, an error was detected.  Unable to provide results!"
              << endl;
         return false;
     }
     cout << "Interest accrued for " << NUM_ONE_MONTH << " months!" << endl;
     cout << "Initial balance: " << initialBalance << endl;
     totalInterest = balanceAmt - initialBalance;
     cout << "Total interest accrued: " << totalInterest << endl;
     cout << "Final balance: " << balanceAmt << endl;
     return true;
 }





bool accrueInterest(
 double &balanceAmt,//alanceAmt is the initial balance and the final balance

 const int numMonths,//numMonths is the number of months

 const bool doPrintEachMonth/*false:function performs silently; true:added
                            interest and the balance will be printed*/
 )
 {
     double interestOfEachMonth;/*floating number for accured interest in
                                a month*/

     double totalInterest;/*floating number for the total interest accured
                          within months*/

     double initialBalance;/*floating number for the amount of money that
                           will be put into the bank*/

     double changedInitialBalance;/*floating number for the changed initial
                                  balance since the 2nd month*/
     

     if (numMonths <= ILLOGICAL_MONTH_NUM_LIMIT)
     {
         cout << "ERROR in accrueInterest: numMonths must be > 0, but the"
              << " value " << numMonths << " was provided!" << endl;
         cout << "Sorry, an error was detected.  Unable to provide results!"
              << endl;
         return false;
     }
     else
     {
         initialBalance = balanceAmt;
         for (int monthNum = 1; monthNum <= numMonths; monthNum++)
         {
             changedInitialBalance = balanceAmt;
             if (balanceAmt < ILLOGICAL_BALANCE_LIMIT)
             {
                 cout << "ERROR in accrueInterest: numMonths must be > 0, but"
                      << " the value " << initialBalance << " was provided!"
                      << endl;
                 cout << "Sorry, an error was detected."
                      << "  Unable to provide results!" << endl;
                 return false;
             }
             if (balanceAmt < SMALLEST_BALANCE_CONDITION)
             {
                 interestOfEachMonth = balanceAmt * SMALLEST_INTEREST_RATE;
                 balanceAmt += interestOfEachMonth;
                 if (doPrintEachMonth)
                 {
                     cout << "Accruing interest for 1 month:" << endl;
                     cout << "  Initial balance: " << initialBalance << endl;
                     cout << "  Initial rate: " << SMALLEST_INTEREST_RATE
                          << endl;
                     cout << "  Interest accrued: " << interestOfEachMonth
                          << endl;
                     cout << "  New balance: " << balanceAmt << endl;
                 }
             }
             else if (balanceAmt >= LARGEST_BALANCE_CONDITION)
             {
                 interestOfEachMonth = balanceAmt * LARGEST_INTEREST_RATE;
                 balanceAmt += interestOfEachMonth;
                 if (doPrintEachMonth)
                 {
                     cout << "Accruing interest for 1 month:" << endl;
                     cout << "  Initial balance: " << changedInitialBalance
                          << endl;
                     cout << "  Initial rate: " << LARGEST_INTEREST_RATE
                          << endl;
                     cout << "  Interest accrued: " << interestOfEachMonth
                          << endl;
                     cout << "  New balance: " << balanceAmt << endl;
                 }
             }
             else if(balanceAmt >= SMALLEST_BALANCE_CONDITION &&
                     balanceAmt < LARGEST_BALANCE_CONDITION)
             {
                 interestOfEachMonth = balanceAmt * MEDIUM_INTEREST_RATE;
                 balanceAmt += interestOfEachMonth;
                 if (doPrintEachMonth)
                 {
                     cout << "Accruing interest for 1 month:" << endl;
                     cout << "  Initial balance: " << changedInitialBalance
                          << endl;
                     cout << "  Initial rate: " << MEDIUM_INTEREST_RATE
                          << endl;
                     cout << "  Interest accrued: " << interestOfEachMonth
                          << endl;
                     cout << "  New balance: " << balanceAmt << endl;
                 }
             }
         }
         cout << "Interest accrued for " << numMonths << " months!" << endl;
         cout << "Initial balance: " << initialBalance << endl;
         totalInterest = balanceAmt - initialBalance;/*compute the total
                                                     accured interest within
                                                     months*/
         cout << "Total interest accrued: " << totalInterest << endl;
         cout << "Final balance: " << balanceAmt << endl;
     }
     return true;
 }
