int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	int i, j, x, y;
 

    int table[value + 1][numDenominations];
     
    
    for (i = 0; i < numDenominations; i++)
        table[0][i] = 1;
 
    
    for (i = 1; i < value + 1; i++)
    {
        for (j = 0; j < numDenominations; j++)
        {
            // Count of solutions including S[j]
            x = (i-denominations[j] >= 0) ? table[i - denominations[j]][j] : 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[value][numDenominations - 1];
}