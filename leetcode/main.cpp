//
//  main.cpp
//  leetcode
//
//  Created by Ying Ying Chen on 2016-06-12.
//  Copyright © 2016 Mia Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class solution
{
public:
   static int RemoveDuplicates(std::vector<int> & array)
    {
        if(array.empty())
        {
            return 0;
        }
        
        
        int index = 1;
        for(int i = 1; i < array.size();i++)
        {
            if(array[i] != array[i-1])
            {
                array[index] = array[i];
                index++;
            }
            
        }
            return index;
        
    }
    
    static int RemoveDuplicatesAllowtwice(std::vector<int> & array)
    {
        if(array.empty())
        {
            return 0;
        }
        
        
        int index = 1;
        int mark = 0;
        
        for(int i = 1; i < array.size(); i++)
        {
            if(array[i] != array[i-1])
            {
                array[index] = array[i];
                
                index++;
                
                mark = 0;
            }
            else
            {
                mark++;
                if(mark<2)
                {
                    index++;
                }
            }
            
        }
        return index;
        
    }
    
    static int SearchInRotatearray(const std::vector<int> & array, int SearchValue)
    {
        int first = 0, last = array.size();
        
        while(first != last)
        {
            const int mid = first + (last - first)/2;
            
            if(array[mid] == SearchValue)
            {
                return mid;
            }
            
            else if(array[first] <= array[mid])
            {
                if(SearchValue < array[mid])
                {
                    last = mid;
                }
                else
                {
                    first = mid;
                }
            }
            else
            {
                if(array[mid] < SearchValue)
                {
                    first = mid;
                }
                else
                {
                    last = mid;
                }
            }
        }
        
        return -1;
    }
    
    static int longestconsecutive(const std::vector<int> & array)
    {
        std::unordered_map<int, bool> used;
        for(auto i:array)
        {
            used[i] = false;
        }
        
        int maxlongest = 0;
        
        for(auto i:array)
        {
            int j = 0;
            
            if(used[i] == true)
            {
                continue;
            }
            else
            {
                used[i] = true;
                int longest = 1;
                
                for(j = i+1; used.find(j)!= used.end(); j++)
                {
                    used[j] = true;
                    longest++;
                }
            
                for(j=i-1; used.find(j)!= used.end(); j--)
                {
                    used[j] = true;
                    longest++;
                }
            
                maxlongest =  maxlongest >= longest? maxlongest: longest;
            }
            
        }
        
        return maxlongest;
    }
    
    static std::vector<int> TwoSum(const std::vector<int> &inputvector, int target)
    {
        std::unordered_map<int,int> map;
        int j = 0;
        std::vector<int> resultarray;
        
        for(auto i:inputvector)
        {
            map[i] = j++;
        }
        
        for(auto i:inputvector)
        {
            int gap = target - i;
            if(map.find(gap)!=map.end() && map[gap] > map[i])
            {
                resultarray.push_back(i);
                resultarray.push_back(gap);
            }
        }
        
        return resultarray;
        
    }
    
    static std::vector<std::vector<int>> ThreeSum(std::vector<int> &inputvector, int target)
    {
        std::vector<std::vector<int>> resultvector;
        
        if(inputvector.size() < 3)
        {
            return resultvector;
        }
        
        std::sort(inputvector.begin(), inputvector.end());
        
        auto begin = inputvector.begin();
        auto last = inputvector.end();

        for(auto i = begin; i < last - 2; i++)
        {
            auto j = i+1;
            if(i > inputvector.begin() && *i == *(i-1))
            {
                continue;
            }
            auto k = last - 1;
            
            while (j<k)
            {
                int sum = *i+*j+*k;
                if(sum == target)
                {
                    resultvector.push_back({*i,*j,*k});
                    ++j;
                    --k;
                    while(j == j-1 && j < k)
                    {
                        ++j;
                    }
                    while (k == k+1 && j < k)
                    {
                        --k;
                    }
                    
                }
                else if(sum < target)
                {
                    ++j;
                    while(*j == *(j-1) && j < k)
                    {
                        ++j;
                    }
                }
                else
                {
                    --k;
                    while(*k == *(k+1) && j < k)
                    {
                        --k;
                    }
                    
                }
            }
            
        }
        
        
        return resultvector;
        
    }
    
    static int ThreeSumCloset(std::vector<int> &inputvector, int target)
    {
        int closetsum = 0;
        int mingap = INT_MAX;
        sort(inputvector.begin(), inputvector.end());
        
        for(auto i = inputvector.begin(); i != prev(inputvector.end(), 2) ; ++i)
        {
            auto j = next(i);
            auto k = prev(inputvector.end());
            
            while(j<k)
            {
                const int sum = *i+*j+*k;
                const int gap = target - sum;
                
                if(gap < mingap)
                {
                    closetsum = sum;
                    mingap = gap;
                }
                
                if(sum < target)
                {
                    ++j;
                    while(*j== *(j-1))
                    {
                        ++j;
                    }
                }
                else
                {
                    --k;
                    while (*k == *(k+1))
                    {
                        --k;
                    }
                }
            }
        }
        
        return closetsum;
    }
    
    static int removeelement(std::vector<int> &inputvector, int target)
    {
        int index = 0;
        for(int i = 0; i< inputvector.size();i++)
        {
            if(inputvector[i] != target)
            {
                inputvector[index] = inputvector[i];
                index++;
            }
        }
        
        return index;
    }
    
    static void addone(std::vector<int> & inputvector, int addnum)
    {
        int carry = addnum;
        for(auto it = inputvector.rbegin(); it!= inputvector.rend(); it++)
        {
            *it = *it + carry;
            carry = *it/10;
            *it = *it%10;
        }
        
        if (carry > 0)
        {
            inputvector.insert(inputvector.begin(), carry);
        }
    }
    
    static int singlenumber(const std::vector<int> & inputvector)
    {
        int returnnumber = 0;
        for(auto i:inputvector)
        {
            returnnumber = i ^ returnnumber;
        }
        
        return returnnumber;
        
    }
    
    static std::vector <std::vector <int> > getLockerDistanceGrid(int cityLength, int cityWidth, std::vector <int> lockerXCoordinates, std::vector <int> lockerYCoordinates)
    {
        std::vector<std::vector<int>> lockervector;
        std::vector<std::vector<int>> resultvector(cityLength, std::vector<int>(cityWidth,0));
    
        for (int i = 0; i < lockerXCoordinates.size(); ++i)
        {
            for(int j = 0; j < lockerYCoordinates.size(); j++)
            {
                if (i == j)
                    lockervector.push_back({lockerXCoordinates[i], lockerYCoordinates[j]});
                
            }
        }
        
        for(int i = 1; i <= cityLength; i++)
        {
            for(int j = 1; j <= cityWidth; j++)
            {
                int min_distance = INT_MAX;
                for(int k = 0; k < lockervector.size(); k++)
                {
                    int xdistance = abs(i - (lockervector[k])[1]);
                    int ydistance = abs(j - (lockervector[k][0]));
                    int distance = xdistance + ydistance;
                    min_distance = min_distance > distance? distance:min_distance;
                }
                resultvector[i-1][j-1] = min_distance;
                
            }
        }
        
        return resultvector;
        
    }
    
    static int singlenumberII(std::vector<int> &inputvector)
    {
        int one = 0, two = 0, three = 0, nonthree = 0;
        
        for(auto i:inputvector)
        {
            two = two | (one & i);
            one = one ^ i;
            three = two & one;
            nonthree = ~three;
            
            two = two & nonthree;
            one = one & nonthree;
        }
        
        return one;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
#if 0
    std::vector<int> array = {2,3,4,4,4,5,6,6,7};
    int index = solution::RemoveDuplicates(array);
    for(int i = 0; i < index; i++)
    {
       std::cout << array[i] << ", ";
    }
    
    std::cout << "\n";
    
    std::vector<int> arrayallowtwice = {2,3,4,4,4,5,6,6,7};
    index = solution::RemoveDuplicatesAllowtwice(arrayallowtwice);
    for(int i = 0; i < index; i++)
    {
        std::cout << arrayallowtwice[i] << ", ";
    }
    
    
    std::vector<int> searcharray = {6,7,8,9,0,1,2,3,4,5};
    std::cout <<"index of search value in rotated array:" << solution::SearchInRotatearray(searcharray,4) << "\n";
    
    
    std::vector<int> LongestConsecutiveArray = {0,9,5,2,3,18,6,7,8};
    std::cout << "\nlongest consecutive number:" << solution::longestconsecutive(LongestConsecutiveArray) <<"\n";
    
    
    std::vector<int> resultvector = solution::TwoSum(searcharray, 14);
    std::cout <<"\ntwo sum: "<<resultvector[0] << "," << resultvector[1] <<"\n";
    
    
    std::vector<std::vector<int>>ThreeSum = solution::ThreeSum(LongestConsecutiveArray, 10);
    std::cout <<"\nthree sum:\n";
    for(auto i:ThreeSum)
    {
        for(auto j:i)
        {
            std::cout << j << ",";
        }
        std::cout<<"\n";
    }
    std::cout <<"\n";
    
    
    std::cout<<"3 sum closet:";
    std::cout << solution::ThreeSumCloset(LongestConsecutiveArray,36)<< "\n";
    
    
    std::cout << "remove element:" << solution::removeelement(LongestConsecutiveArray, 18) <<"\n";
    
    std::vector<int> addonevector = {2,3,6};
    std::cout << "add one number:" << "\n";
    solution::addone(addonevector , 5);
    for(auto i:addonevector)
    {
        std::cout << i;
    }
    std::cout<<"\n";
    
    
    std::vector<int> singlenumbervector= {2,5,7,7,9,3,4,2,5,3,4};
    std::cout<<"single number:"<<solution::singlenumber(singlenumbervector)<<"\n";
    
    std::vector<int> lockerx = {2,4};
    std::vector<int> lockery = {3,7};
    //std::vector<std::vector<int>> gridvector = {{2,4},{3,7}};
    std::vector<std::vector<int>> gridresultvecot;
    gridresultvecot = solution::getLockerDistanceGrid(7,5,lockerx,lockery);
    
    std::cout<<"gird: \n";
    
    for(int i = 0; i< 7;i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::cout<< gridresultvecot[i][j];
        }
        std::cout << ",\n";
    }
#endif
    
    std::vector<int> singleonevector = {1,2,3,4,2,3,1,3,2,1};
    std::cout <<"single number II:"<< solution::singlenumberII(singleonevector) <<"\n";

    return 0;
}
