/*
���ڿ� ������ ������ ���� ���� �� ���� ���͸� ��ȯ�ϴ� �Լ��� N log(2) N �� ���⼺�� ���� �ڵ带 �����Ͻÿ�.
{ 0, 'a', 'c', 4, 1, 2, 'b', 0, 2, 3 } �Է½� {1, 6}�� ���, �ֳ��ϸ� the subvector {'a', 'c', 4, 1, 2, 'b'} �̹Ƿ�, ���� 3��, ���� 3��

*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cctype>

std::pair<int, int> identifySubvector(std::vector<unsigned char> const& digitCharVec) {

    int idxBeg = 0; // beginning index of the longest subvector
    int idxEnd = 0; // endding index of the longest subvector
    int maxLen = 0; // length of of the longest subvector

    //���ڿ� , ���ڿ�  ���� ���� ����� 
    //0 : ���� ������ ����,  1: ���� ������ ����
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

        //�ϳ��� �ö󰡴ٰ�  ���� maxLen���� �Ѵ� ���̰� Ŀ����
        if (maxLen < digitLen && maxLen < charLen) {
            //maxLen�� �ø���,  
            ++maxLen;
            //idxEnd�� ������ġ���� idxBeg�� ã���ֱ�

            //������� idxBeg�� ã���������?
            //���� ���� digitLen, charLen���� maxLen���� ���ϱ� 1�� ���� ó���ߴ� ��ġ

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
       std::cout << "������ : " << data;
       std::cout << "���� ����  : " << lenSavesData[0][i] << " ";
       std::cout << "���� ����  : " << lenSavesData[1][i] << std::endl;
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