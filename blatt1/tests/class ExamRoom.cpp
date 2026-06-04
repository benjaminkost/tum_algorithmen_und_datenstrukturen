class ExamRoom {
private:
    vector<int> seats; 
public:
    ExamRoom(int n) {
        this->seats.assign(n,0);
    }
    
    int seat() {
        int tempIndexDifference = 0;
        int maxIndexDifference = 0;
        int sum = 0;
        int startIndex = 0;
        int resultingSeat = 0;
        int completeSumPrev = 0;
        int completeSumAfter = 0;

        for (int x : this->seats){
            completeSumPrev += x;
        }

        if (completeSumPrev == 0) {
            this->seats[0] = 1;
            printf("Manual: %i\n", 0);
            return 0;
        } else if(completeSumPrev == 1 && this->seats[0] == 1) {
            this->seats[this->seats.size()-1] = 1;
            printf("Manual: %i\n", this->seats.size()-1);
            return this->seats.size()-1;
        } else if(completeSumPrev == 1 && this->seats[this->seats.size()-1] == 1) {
            this->seats[0] = 1;
            printf("Manual: %i\n", 0);
            return 0;
        }

        for (int i = 0; i < this->seats.size(); i++){
            sum += this->seats[i];
            completeSumAfter+= this->seats[i];
            if (sum == 2 || (startIndex == 0 && i != 0 && (this->seats[i] == 1))) {
                tempIndexDifference = (i-startIndex)/2;
                if (startIndex == 0 && i != 0 && (this->seats[i] == 1) && this->seats[0] == 0){
                    tempIndexDifference = i;
                }
                printf("TEMP: %i, %i, %i\n", resultingSeat, startIndex, i);
                if (maxIndexDifference < tempIndexDifference) {
                    if (startIndex == 0 && i != 0 && (this->seats[i] == 1) && this->seats[0] == 0){
                        maxIndexDifference = tempIndexDifference;
                        resultingSeat = maxIndexDifference-1;
                    } else {
                        maxIndexDifference = tempIndexDifference;
                        resultingSeat = maxIndexDifference+startIndex;
                    }
                    printf("%i, %i, %i\n", resultingSeat, startIndex, i);
                    completeSumAfter+= 1;
                }
                startIndex = i;
                sum = 1;
            }
        }

        int differenceWithEnd = 0;

        if (completeSumPrev == completeSumAfter && this->seats[this->seats.size()-1] == 0) {
            differenceWithEnd = (this->seats.size()-startIndex)/2;
            if (differenceWithEnd > maxIndexDifference) {
                if (this->seats[this->seats.size()-1] == 0) {
                    this->seats[this->seats.size()-1]=this->seats.size()-1;
                    printf("Korrektion: %i\n", startIndex);
                    return this->seats.size()-1;
                }
                this->seats[startIndex]=1;
                printf("Korrektion: %i\n", startIndex);
                return startIndex;
            }
        }
 
        this->seats[resultingSeat]=1;
        return resultingSeat;
    }
    
    void leave(int p) {
        this->seats[p] = 0;

    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */