/*
숫자와 문자의 개수가 같은 가장 긴 하위 벡터를 반환하는 함수를 N log(2) N 의 복잡성을 가진 코드를 구현하시오.
{ 0, 'a', 'c', 4, 1, 2, 'b', 0, 2, 3 } 입력시 {1, 6}를 출력, 왜냐하면 the subvector {'a', 'c', 4, 1, 2, 'b'} 이므로, 숫자 3개, 문자 3개

*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cctype>

std::pair<int, int> identifySubvector(std::vector<unsigned char> const& digitCharVec) {

    int idxBeg = 0; // beginning index of the longest subvector
    int idxEnd = 0; // endding index of the longest subvector
    int maxLen = 0; // length of of the longest subvector

    //숫자용 , 문자용  누적 길이 저장용 
    //0 : 숫자 누적수 저장,  1: 문자 누적수 저장
    // variable for cumulative digits and characters
    std::vector<int> lenSavesData[2]; // lenSavesData[0]: Saving cumulative digit numbers, lenSavesData[0]: Saving cumulative characters

    int digitLen = 0;
    int charLen = 0;
    int nowIdx = 0;
    for (auto& data : digitCharVec) {
        
        if (isalpha(data)) { // if data is character
            ++charLen;
        }
        else if (data <= 9) { // if data is digit number
            ++digitLen;
        }        
        else { // if data is other.

        }
        lenSavesData[0].push_back(digitLen);
        lenSavesData[1].push_back(charLen);

        //하나씩 올라가다가  기존 maxLen보다 둘다 길이가 커지면
        if (maxLen < digitLen && maxLen < charLen) {
            //maxLen을 올리고,  
            ++maxLen;
            //idxEnd는 현재위치지만 idxBeg를 찾아주기

            //어느놈의 idxBeg를 찾아줘야하지?
            //현재 가진 digitLen, charLen에서 maxLen빼고 더하기 1한 값이 처음뜨는 위치

            int findValue_digit = digitLen - maxLen + 1;
            int findValue_char = charLen - maxLen + 1;

            int findDigitIdx = std::lower_bound(lenSavesData[0].begin(), lenSavesData[0].end(), findValue_digit) - lenSavesData[0].begin();
            int findCharIdx = std::lower_bound(lenSavesData[1].begin(), lenSavesData[1].end(), findValue_char) - lenSavesData[1].begin();

            idxBeg = std::min(findDigitIdx, findCharIdx);
            idxEnd = nowIdx;
        }
        ++nowIdx;
    }
    int i = 0;
    for (auto& data : digitCharVec) {
       std::cout << "데이터 : " << data;
       std::cout << "누적 숫자  : " << lenSavesData[0][i] << " ";
       std::cout << "누적 문자  : " << lenSavesData[1][i] << std::endl;
       ++i;
    }


    return { idxBeg, idxEnd };
}


int main()
{

    //std::vector<unsigned char> digitCharVec = { 0,'a' };
    std::vector<unsigned char> digitCharVec = { 0, 'a', 'c', 4, 1, 2, 'b', 0, 2, 3 };

    std::pair<int, int> result = identifySubvector(digitCharVec);

    std::cout << result.first << ", " << result.second;

}