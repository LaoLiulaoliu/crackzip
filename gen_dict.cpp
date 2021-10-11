#include <fstream>
#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 62
const string alphanum = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

int comb(string password, int idx, int length, ofstream& file)
{
    if (idx == length) {
        return 0;
    }

    for (size_t i = 0; i < alphanum.size(); i++) {
        string tmp = password + alphanum[i];
        comb(tmp, idx + 1, length, file);
        file << tmp << endl;
    }
    return 0;

}

int main(int argc, char **argv)
{
    ofstream file;
    file.open("combcpp.txt");

	string password = "";
    comb(password, 0, 5, file);

    file.close();
    return 0;
}


int multi_comb()
{
    pthread_t threads[NUM_THREADS];
    int ret;
    for(int i = 0; i < NUM_THREADS; ++i) {
        ret = pthread_create(&threads[i], NULL, comb, );
        if (ret != 0) {
            cout << "Error: can not create thread: " << ret << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}