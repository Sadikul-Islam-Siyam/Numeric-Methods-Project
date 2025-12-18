//author: tahmids55
#include <bits/stdc++.h>
using namespace std;

// File Operation Class
class FileIO{
private:
    ifstream in;
    ofstream out;

public:
    FileIO(){}

    bool openInput(const string &filename = "../Input/input.txt"){
        in.open(filename);
        if(!in.is_open()){
            cerr << "Cannot open input file: " << filename << endl;
            return false;
        }
        return true;
    }

    bool openOutput(const string &filename = "../Output/output.txt"){
        out.open(filename);
        if(!out.is_open()){
            cerr << "Cannot open output file: " << filename << endl;
            return false;
        }
        return true;
    }

    template<typename T>
    void print(const T &val){
        cout << val;
        out  << val;
        out.flush();
    }

    template<typename T>
    void printToFile(const T &val){
        out << val;
        out.flush();
    }

    ifstream& input(){
        return in;
    }

    void closeFiles(){
        if(in.is_open())  in.close();
        if(out.is_open()) out.close();
    }

    ~FileIO(){
        closeFiles();
    }
};

float dydx(float x, float y){
    return (x - y) / 2;
}

float rungeKutta(float x0, float y0, float x, float h){
    int n = (int)((x - x0) / h);
    float y = y0;

    for(int i = 0; i < n; i++){
        float k1 = h * dydx(x0, y);
        float k2 = h * dydx(x0 + 0.5f * h, y + 0.5f * k1);
        float k3 = h * dydx(x0 + 0.5f * h, y + 0.5f * k2);
        float k4 = h * dydx(x0 + h, y + k3);

        y += (k1 + 2*k2 + 2*k3 + k4) / 6.0f;
        x0 += h;
    }

    return y;
}

int main(){
    FileIO fileio;

    if(!fileio.openInput()) return 1;
    if(!fileio.openOutput()) return 1;

    float x0, y0, x, h;
    
    // Reading from file
    if(fileio.input() >> x0 >> y0 >> x >> h){
        fileio.print("=== Runge Kutta Method ===\n");
        fileio.print("Initial Condition (x0, y0): (" + to_string(x0) + ", " + to_string(y0) + ")\n");
        fileio.print("Target x: " + to_string(x) + "\n");
        fileio.print("Step size h: " + to_string(h) + "\n");

        float result = rungeKutta(x0, y0, x, h);
        
        fileio.print("\nResult y(" + to_string(x) + ") = " + to_string(result) + "\n");
    } else {
        cout << "Error reading input data." << endl;
    }

    fileio.closeFiles();
    return 0;
}
