#define TIME_H
using namespace std;
struct House {
    string roadNameAddress; //도로명 주소
    double monthly;     // 월세 + 관리비
    double deposit;      // 보증금
    double distance;    // 신공학관으로부터 거리
    double size;         // 평수
    double floor;          // 층수
    bool security; // 공동현관 유무, cctv
};


