#include <iostream>
#include <cstdlib>

using namespace std;

int tradeOutputVal(int riskHundrethOfPercent, int winratePercent, int numberOfTrials, int initialCash)
{
    srand((unsigned) time(NULL));

    int cashAmount = initialCash;
    bool cashDoubled = false;

    cout << "cash amount: " << cashAmount << endl;


    for (int i = 0; i < numberOfTrials; i++)
    {
        if (rand() % 100 < winratePercent)
        {
            cashAmount += ((cashAmount / 10000) * riskHundrethOfPercent);
        } else {
            cashAmount -= ((cashAmount / 10000) * riskHundrethOfPercent);
        }
        
        if (cashAmount > initialCash * 2 && !cashDoubled)
        {
            cout << "\naccount doubled" << endl;
            cout << "it took " << i + 1 << " trades\n" << endl;
            cashDoubled = true;
        }

        cout << "cash amount: " << cashAmount << endl;
    }

    cout << "analysis done" << endl;

    return 0;
}

// 10000 trials to see how many trials are needed in average
int averageDoubling(int riskHundrethOfPercent, int winratePercent)
{
    srand((unsigned) time(NULL));

    int cashAmount = 100000;
    bool cashDoubled = false;

    int trialsThatCounted = 0;
    int trialsThatFailed = 0;

    int totalCount = 0;

    int worstRun = 0;

    for (int i = 0; i < 10000; i++)
    {
        int output = 0;
        int cashAmount = 100000;

        for (int i = 0; i < 10000; i++)
        {
            if (rand() % 100 < winratePercent)
            {
                cashAmount += ((cashAmount / 10000) * riskHundrethOfPercent);
            } else {
                cashAmount -= ((cashAmount / 10000) * riskHundrethOfPercent);
            }
            
            if (cashAmount > 100000 * 2)
            {
                output = i;
                break;
            }
        }

        if (output == 0) {
            trialsThatFailed += 1;
        } else {
            // cout << output << endl;
            if (worstRun < output) {
                worstRun = output;
            }
            trialsThatCounted += 1;
            totalCount += output;
        }
    }

    cout << "worst run = " << worstRun << endl;
    cout << "trialsThatCounted = " << trialsThatCounted << endl;
    cout << "average: " << totalCount / trialsThatCounted << endl;
    return 0;
}