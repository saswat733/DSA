 for(int i=first_col;i<last_col && count<total;i++){
            ans.push_back(a[first_row][i]);
            count++;
        }
        first_row++;

        for(int i=first_row;i<last_row && count<total;i++){
            ans.push_back(a[i][last_col]);
            count++;
        }
        last_col--;


        for(int i=last_col;i>=first_col&& count<total;i--){
            ans.push_back(a[last_row][i]);
            count++;
        }
        last_row--;

        for(int i=last_row;i>=first_row&& count<total;i--){
            ans.push_back(a[first_col][i]);
            count++;
        }
        first_col++;