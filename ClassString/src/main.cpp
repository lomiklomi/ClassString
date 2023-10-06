#include <IString.h>
#include <locale.h>
#include <vector>
#include <algorithm>
#include <string>
#include <Sort.h>

int main() {
    char* locale = setlocale(LC_ALL, "");
 
    // Êîä-ïğèìåğ
    printf("ÏĞÎÃĞÀÌÌÀ-ÏĞÈÌÅĞ\n\n");
    std::vector<IString> vec1{"ch1", "Hello", "World!", "Aasfasfas", "Bfasfasfa", "Cavavasafd"};
    vec1[1] = vec1[3] + vec1[3];
    vec1[0] += vec1[4];

    printf("Elements: \n");
    for (int i = 0; i < vec1.size(); i++) {
        vec1[i].Print();
    }

    ReverseCaseInsensitiveSort(vec1);

    printf("\nAfter sorting the elements are: \n");

    for (int i = 0; i < vec1.size(); i++) {
        vec1[i].Print();
    }
}