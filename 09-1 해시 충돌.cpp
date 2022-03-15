#include <iostream>

using namespace std;
/*
ㅇ충돌
-해시 함수가 각각의 키에 대해서 가급적이면 고유한 해쉬값을 반환해야하는데
서로다른 키에 대해서 같은 해시 값을 반환함으로써, 두개 이상의 데이터가 해시 테이블에서 같은 위치에 저장되려는 현상이다.
-해시테이블의 크기가 저장할 데이터의 개수보다 작으면 반드시 충돌이 발생
반대로 개수가 크더라도 해시 함수의 동작에 따라 충돌이 발생할 수 있다.

ㅇ대표적인 충돌 처리 기법

1.Chaning
-해시 테이블의 특정 위치에서 하나의 키를 저장하는 것이 아니라 하나의 연결리스틀 저장하는 기법이다.
separate chaning이라고도 한다.
-새로 삽입된 키에 의해 충돌이 발생하면 리스트에 새로운 키를 추가한다.
ex) hash(x) = x%7
포인터를 가진 배열로 초기화 하고 . 다 null값을 가진 상태.
이떄 새로운 데이터를 삽입하면 추가한후 , 또 추가하는데 같으면 연결리스트의 맨 앞에 새로운 값을 추가 한다.

-만약에 키와 벨류쌍을 저장하고 싶으면 캐와 벨류를 같이 저장하는 형태의 연결리스트를 사용할 수 있다.

-체이닝 특징
삽입 연산은 O(1)의 시간 복잡도로 동작한다.
->기본적으로 해쉬 테이블에 몇번째 위치에 저장할지를 계산하는 해쉬함수의 복잡도가 O(1)로 동작하게 된다.

탐색하는 시간은 최악의 경우 모든 데이터가 같은 해시값을 가질 경우, 하나의 연결리스트에 모든 데이터가 저장이 될 경우, 이 연결리스트를 다 조사해야하기 때문에
O(n)으로 동작하게 된다.

삭제를 진행할 때에도 탐색을 먼저 수행을 해야하기 때문에 최악의 경우에 O(n)으로 동작하게 된다.

이를 위해서
-부하율과 재해싱을 사용할 수 있다.
부하율(load factor) : 해시 테이블에서 각각의 리스트에 저장되는 데이터(키)의 평균 개수를 나타낸다. (적재율 이라고도한다)

alpha = n/m ( n : 해시 테이블에 저장할 전체의 키의 갯수, m : 해시 테이블의 크기 (연결리스트 갯수))

부하율이 1보다 작으면, 저장할 데이터 갯수보다 해시테이블을 크게 잡았을 경우다. 이 경우 메모리의 낭비가 될 수 있고,
1보다 크면 충돌이 많이 발생할것이고 각각의 연결리스트에 저장되는 데이터의 갯수가 크게 증가하기 때문에
탐색 또는 삭제 연산이 느리게 동작할 수 있다.
그렇기 때문에 부하율 값이 크면 재해싱(rehashing)을 통해 부하율이 1에 가까운 값이 되도록 조정할 수 있다.

2. Open addressing
-해싱 충돌이 발생할 경우 ,해시 테이블에서 다른 비어있는 버킷을 찾아 데이터를 저장하는 방식이다.
열린주소지정이라고 한다.
-해시 테이블의 크기가 데이터 개수보다 커야한다!

-새로운 위치 탐사(probing)방법
1.선형탐사(linear probing)
-해시테이블에서 충돌이 발견하면 해당위치 다음 위치에 데이터를 저장한다.
만약에 다음 위치에도 데이터가 존재하면 반복적으로 그 다음 위치를 찾는다
즉 h(key)가 사용중이면 h(key) + 1 , h(key) + 2 .... 순서로 빈 위치를 찾는다.
-데이터가 특정 위치에 군집화(clustering) 될 수 있다. 그러면 해싱 효율이 떨어질 수 있다.

2.제곱탐사(quadratic probing)
-고정 크기로 이동하는 성형 탐사와 달리 제곱 수 크기로 이동하면서 비어 있는 위치를 찾는 방식이다.
즉 h(key)가 사용중이면 h(key) + 1^2 , h(key) 2^2... 순서로 빈 위치를 찾는다
-군집화를 피하기 위해 간격을 두고 데이터를 삽입하는 방식이다.

3.이중해싱)
-2개의 해시 함수를 사용하여 
충돌이 발생하면 다른 해시 함수로 닷 ㅣ해시값을 만들어 낸 후 원소를 검사하는 것.


3. Cuckoo hashing(뻐꾸기 해싱)
임의의 길이를 갖는 메세지를 받아 일정한 길이의 해시 값을 추출하는 함수이다.
-입력값의 길이가 달라도 출력 값은 언제나 고정된 길이로 반환한다
-눈사태 효과가 일어날 수 있다 : 입력 값의 아주 일부만 변경되어도 전혀 다른 결과 값을 출력한다
-출력된 결과 값을 토대로 입력 값을 유추할 수가 없다
-동일한 값이 입력되면 언제나 동일한 출력값을 보장한다.
*/


#include<vector>
#include<list>
class hash_set
{
private:
    int sz;
    vector<list<int>> data;
public:
    hash_set(int n) : sz(n), data(sz) { } // 모두변수 -1로 초기화 !

    int hash(int key) { return key % sz; }

    void insert(int value) { data[hash(value)].push_back(value); }

    bool find(int value) { 
        auto& entries = data[hash(value)];
        return std::find(entries.begin(), entries.end(), value) != entries.end(); // 벨류값을 찾아서 end와 비교한다. 벨류가 존재하면 true, 없으면 false가 반환
    }
    void erase(int value) {
        auto& entries = data[hash(value)];
        auto it = std::find(entries.begin(), entries.end(), value); // 찾고자하는 값의 반복자를 it로 받게된다 

        if (it != entries.end()) entries.erase(it); // 만약에 존재한다면 end와 다르니깐 해당 위치 데이터를 삭제하게 된다.
    }
    
    void print() {

        for (int i = 0; i < sz; i++) {
            cout << i << " : ";
            for (auto n : data[i]) {
                cout << n << "  , ";
            }
            cout << endl;
        }
    }

};

int main() {

    hash_set num_set(7);

    num_set.insert(10); // 3번째 자리에 10이라는 값이 들어가게 됨
    num_set.insert(15); // 첫번쨰 자리에 15가 들어가게 됨
    num_set.insert(20); // 6번쨰 자리에 20이 들어가게 됨
    num_set.insert(100); // 2번째 자리에 100값이 들어감

    int value = 10;

    if (num_set.find(value)) cout << value << " found " << endl;
    else cout << value << "not found " << endl;

    num_set.insert(2); // 체이닝 기법을 사용함 

     value = 100;

    if (num_set.find(value)) cout << value << " found " << endl; // 체이닝 기법을 사용해서 발견함
    else cout << value << "not found " << endl;

    num_set.print();
}