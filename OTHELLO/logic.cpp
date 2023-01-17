#include <iostream>

using namespace std;

/* If the output of the logic function was zero,
   it means that the operation performed by the player is correct.
*/
int Logic(int x, int y ,string array[12][12] ,string symbol1 ,string symbol2 ,int size ,int CheckTurn ,int &picees1 ,int &picees2)
{
    // Right
    bool Check = false;
    int temp;
    bool flag = false;
    if (array[x][y] == " ")
    {
        for (int i = y + 1; i < size; i++)
        {
            if(i == y + 1 and array[x][i] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == y + 1 and array[x][i] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (array[x][i] == symbol1 and CheckTurn == 0 and array[x][i] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if (i != y + 1 and array[x][i] == symbol2 and CheckTurn == 1 and array[x][i] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if(array[x][i] == " ") 
                break;
        }

        if (flag == true and CheckTurn == 0)
        {
            for (int j = y + 1; j < temp; j++)
            {
                array[x][j] = symbol1;
                picees1++;
                picees2--;
            }            
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = y + 1; j < temp; j++)
            {
                array[x][j] = symbol2;
                picees1--;
                picees2++;
            }            
            Check = true;
        }

        
        // Left
        flag = false;
        temp = 0;
        for (int i = y - 1; i >= 0; i--)
        {
            if(i == y - 1 and array[x][i] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == y - 1 and array[x][i] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != y - 1 and array[x][i] == symbol1 and CheckTurn == 0 and array[x][i] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if (i != y - 1 and array[x][i] == symbol2 and CheckTurn == 1 and array[x][i] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if(array[x][i] == " ") 
                break;
        }

        if (flag == true and CheckTurn == 0)
        {
            for (int j = y - 1; j > temp; j--)
            {
                array[x][j] = symbol1;
                picees1++;
                picees2--;
            }            
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for(int j = y - 1; j > temp; j--)
            {
                array[x][j] = symbol2;
                picees1--;
                picees2++;
            }            
            Check = true;
        }

        
        // Up
        flag = false;
        temp = 0;
        for (int i = x - 1; i >= 0; i--)
        {
            if(i == x - 1 and array[i][y] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == x - 1 and array[i][y] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != x - 1 and array[i][y] == symbol1 and CheckTurn == 0 and array[i][y] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if (i != x - 1 and array[i][y] == symbol2 and CheckTurn == 1 and array[i][y] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if(array[i][y] == " ") 
                break;
        }

        if (flag == true and CheckTurn == 0)
        {
            for (int j = x - 1; j > temp; j--)
            {
                array[j][y] = symbol1;
                picees1++;
                picees2--;
            }            
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = x - 1; j > temp; j--)
            {
                array[j][y] = symbol2;
                picees1--;
                picees2++;
            }            
            Check = true;
        }
        

        // Down
        flag = false;
        temp = 0;
        for (int i = x + 1; i < size; i++)
        {
            if(i == x + 1 and array[i][y] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == x + 1 and array[i][y] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != x + 1 and array[i][y] == symbol1 and CheckTurn == 0 and array[i][y] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if (i != x + 1 and array[i][y] == symbol2 and CheckTurn == 1 and array[i][y] != " ")
            {
                temp = i;
                flag = true;
                break;
            }
            else if(array[i][y] == " ") 
                break;

        }

        if (flag == true and CheckTurn == 0)
        {
            for (int j = x + 1; j < temp; j++)
            {
                array[j][y] = symbol1;
                picees1++;
                picees2--;
            }            
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = x + 1; j < temp; j++)
            {
                array[j][y] = symbol2;
                picees1--;
                picees2++;
            }            
            Check = true;
        }

        
        // diagonal Down Left
        flag = false;
        int tempx = 0;
        int tempy = 0;
        int j = y - 1;

        for (int i = x + 1; i < size; i++)
        {
            if(i == x + 1  and j == y - 1 and array[i][j] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == x + 1  and j == y - 1 and array[i][j] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != x + 1  and j != y - 1 and array[i][j] == symbol1 and CheckTurn == 0 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if (i != x + 1 and j != y - 1 and array[i][j] == symbol2 and CheckTurn == 1 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if(array[i][j] == " ") 
                break;  
            j--;
        }

        int k = y - 1;
        if (flag == true and CheckTurn == 0)
        {
            for (int j = x + 1; j < tempx; j++)
            {
                array[j][k] = symbol1;
                k--;
                picees1++;
                picees2--;
            }
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = x + 1; j < tempx; j++)
            {
                array[j][k] = symbol2;
                k--;
                picees1--;
                picees2++;
            }    
            Check = true;
        }
        

        //diagonal Up Right
        flag = false;
        tempx = 0;
        tempy = 0;
        j = y + 1;

        for (int i = x - 1; i >= 0; i--)
        {
            if(i == x - 1  and j == y + 1 and array[i][j] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == x - 1  and j == y + 1 and array[i][j] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != x - 1  and j != y + 1 and array[i][j] == symbol1 and CheckTurn == 0 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if (i != x - 1 and j != y + 1 and array[i][j] == symbol2 and CheckTurn == 1 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if(array[i][j] == " ") 
                break; 
            j++;
        }

        k = y + 1;
        if (flag == true and CheckTurn == 0)
        {
            for (int j = x - 1; j > tempx; j--)
            {
                array[j][k] = symbol1;
                k++;
                picees1++;
                picees2--;
            }
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = x - 1; j > tempx; j--)
            {
                array[j][k] = symbol2;
                k++;
                picees1--;
                picees2++;
            }    
            Check = true;
        }

        
        //diagonal Up Left
        flag = false;
        tempx = 0;
        tempy = 0;
        j = y - 1;

        for (int i = x - 1; i >= 0; i--)
        {
            if(i == x - 1  and j == y - 1 and array[i][j] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == x - 1  and j == y - 1 and array[i][j] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != x - 1  and j != y - 1 and array[i][j] == symbol1 and CheckTurn == 0 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if (i != x - 1 and j != y - 1 and array[i][j] == symbol2 and CheckTurn == 1 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if(array[i][j] == " ") 
                break;   
            j--;
        }

        k = y - 1;
        if (flag == true and CheckTurn == 0)
        {
            for (int j = x - 1; j > tempx; j--)
            {
                array[j][k] = symbol1;
                k--;
                picees1++;
                picees2--;
            }
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = x - 1; j > tempx; j--)
            {
                array[j][k] = symbol2;
                k--;
                picees1--;
                picees2++;
            }    
            Check = true;
        }


        // diagonal Down Right
        flag = false;
        tempx = 0;
        tempy = 0;
        j = y + 1;

        for (int i = x + 1; i < size; i++)
        {
            if(i == x + 1  and j == y + 1 and array[i][j] == symbol1 and CheckTurn == 0)
            {
                break;
            }
            else if(i == x + 1  and j == y + 1 and array[i][j] == symbol2 and CheckTurn == 1)
            {
                break;
            }
            else if (i != x + 1  and j != y + 1 and array[i][j] == symbol1 and CheckTurn == 0 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if (i != x + 1 and j != y + 1 and array[i][j] == symbol2 and CheckTurn == 1 and array[i][j] != " ")
            {
                tempx = i;
                tempy = j;
                flag = true;
                break;
            }
            else if(array[i][j] == " ")
                break;   
            j++;
        }

        k = y + 1;
        if (flag == true and CheckTurn == 0)
        {
            for (int j = x + 1; j < tempx; j++)
            {
                array[j][k] = symbol1;
                k++;
                picees1++;
                picees2--;
            }
            Check = true;
        }
        else if (flag == true and CheckTurn == 1)
        {
            for (int j = x + 1; j < tempx; j++)
            {
                array[j][k] = symbol2;
                k++;
                picees1--;
                picees2++;
            }    
            Check = true;
        } 
    }


    if (!Check)
    {
        return -1;
    }
    
    if (CheckTurn == 0)
    {
        picees1++;
    }
    else
    {
        picees2++;
    }

    return 0;
}


int checkChangeTurn(string array[12][12] ,int size ,int CheckTurn, string symbol1 ,string symbol2)
{
    bool flag = false;
    for(int k=0; k < size;k++){
        for(int c=0; c < size; c++){
            if(array[k][c] == " "){
                // rigth
                int i;
                for (int i = c + 1; i < size; i++)
                {
                    if ((array[k][i] == symbol1 and CheckTurn == 0 and i == c + 1) or array[k][i] == " ")
                    {
                        break;
                    }
                    else if ((array[k][i] == symbol2 and CheckTurn == 1 and i == c + 1) or array[k][i] == " ")
                    {
                        break;
                    }
                    else if (array[k][i] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[k][i] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                }

                // left
                for (int i = c - 1; i >= 0; i--)
                {
                    if ((array[k][i] == symbol1 and CheckTurn == 0 and i == c - 1) or array[k][i] == " ")
                    {
                        break;
                    }
                    else if ((array[k][i] == symbol2 and CheckTurn == 1 and i == c - 1) or array[k][i] == " ")
                    {
                        break;
                    }
                    else if (array[k][i] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[k][i] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                }
                
                // up
                for (int i = k - 1; i >= 0; i--)
                {
                    if ((array[i][c] == symbol1 and CheckTurn == 0 and i == k - 1) or array[i][c] == " ")
                    {
                        break;
                    }
                    else if ((array[i][c] == symbol2 and CheckTurn == 1 and i == k - 1) or array[i][c] == " ") 
                    {
                        break;
                    }
                    else if (array[i][c] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[i][c] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                }

                // down
                for (int i = k + 1; i < size; i++)
                {
                    if ((array[i][c] == symbol1 and CheckTurn == 0 and i == k + 1) or array[i][c] == " ")
                    {
                        break;
                    }
                    else if ((array[i][c] == symbol2 and CheckTurn == 1 and i == k + 1) or array[i][c] == " ") 
                    {
                        break;
                    }
                    else if (array[i][c] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[i][c] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                }

                // diagonal down left
                int j = c - 1;
                for (int i = k + 1; i < size; i++)
                {
                    if ((array[i][j] == symbol1 and CheckTurn == 0 and i == k + 1 and j == c - 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if ((array[i][j] == symbol2 and CheckTurn == 1 and i == k + 1 and j == c - 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if (array[i][j] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[i][j] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                    j--;
                }

                // diagonal up rigth
                j = c + 1;
                for (int i = k - 1; i >= 0; i--)
                {
                    if ((array[i][j] == symbol1 and CheckTurn == 0 and i == k - 1 and j == c + 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if ((array[i][j] == symbol2 and CheckTurn == 1 and i == k - 1 and j == c + 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if (array[i][j] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[i][j] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                    j++;
                }

                // diagonal up left
                j = c - 1;
                for (int i = k - 1; i >= 0; i--)
                {
                    if ((array[i][j] == symbol1 and CheckTurn == 0 and i == k - 1 and j == c - 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if ((array[i][j] == symbol2 and CheckTurn == 1 and i == k - 1 and j == c - 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if (array[i][j] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[i][j] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                    j--;
                }

                // diagonal down right
                j = c + 1;
                for (int i = k + 1; i < size; i++)
                {
                    if ((array[i][j] == symbol1 and CheckTurn == 0 and i == k + 1 and j == c + 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if ((array[i][j] == symbol2 and CheckTurn == 1 and i == k + 1 and j == c + 1) or array[i][j] == " ")
                    {
                        break;
                    }
                    else if (array[i][j] == symbol1 and CheckTurn == 0)
                    {
                        flag = true;
                        break;
                    }
                    else if (array[i][j] == symbol2 and CheckTurn == 1)
                    {
                        flag = true;
                        break;
                    }
                    j++;
                }
                if (flag)
                {
                    return 0;
                }
            }         
        }
    }
    return -1;
}

// This function checks whether the game is over or not.
int checkEnd(string array[12][12] ,int size ,int CheckTurn, string symbol1 ,string symbol2)
{
    int check = checkChangeTurn(array ,size , CheckTurn ,symbol1 ,symbol2);
    while (true)
    {
        check += checkChangeTurn(array ,size , CheckTurn ,symbol1 ,symbol2);
        if (check != 0)
        {
            if (check == -2)
            {
                return -1;
            }
        }
        else
        {
            return 1;
        }
    }
}


string checkWinner(int Turn ,int picees1 ,int picees2, int size ,string user1 ,string user2 ,string TableInfo[][12] ,string symbol1 ,string symbol2)
{
    string winner;
    if (picees1 + picees2 == size * size)
    {
        if (picees1 > picees2)
        {
            winner = user1;
        }
        else if(picees2 > picees1)
        {
            winner = user2;
        } 
        else
            winner = "equal";
        return winner;               
    }
    else if (checkEnd(TableInfo ,size ,Turn, symbol1 ,symbol2) == -1)
    {
        if(picees1 > picees2)
        {
            winner = user1;
        }
        else if(picees2 > picees1)
        {
            winner = user2;
        }
        else
            winner = "equal"; 
        return winner;
    }
    return "0";
}