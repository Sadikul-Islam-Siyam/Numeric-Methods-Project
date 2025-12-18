//Author :: tahmids55
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class NewtonInterpolation{
private:
    int n;
    double y;
    vector<double> x , f;
    vector<vector<double>> dif;  // forward difference table
    vector<vector<double>> bif;  // backward difference table
    double h , u ;
    double fores , backres;
    bool forward_calculated;
    bool backward_calculated;

    // Recursive function for forward interpolation
    double recur(double i, double u){
        if(i == 0) return 1;
        if(i == 1) return u;
        return (u - i + 1) / i * recur(i - 1, u);
    }

    // Recursive function for backward interpolation
    double becur(double i, double u){
        if(i == 0) return 1;
        if(i == 1) return u;
        return (u + i - 1) / i * becur(i - 1, u);
    }

    // Calculate forward difference table
    void calculateForwardDifference(){
        dif.assign(n, vector<double>(n, 0));
        for(int i = 0; i < n; i++){
            dif[i][0] = f[i];
        }
        
        int cur = n;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < cur - 1; j++){
                dif[j][i] = dif[j + 1][i - 1] - dif[j][i - 1];
            }
            cur--;
        }
    }

    // Calculate backward difference table
    void calculateBackwardDifference(){
        bif.assign(n, vector<double>(n, 0));
        for(int i = 0; i < n; i++){
            bif[i][0] = f[i];
        }
        
        int cur = 0;
        for(int i = 1; i < n; i++){
            for(int j = n - 1; j > cur; j--){
                bif[j][i] = bif[j][i - 1] - bif[j - 1][i - 1];
            }
            cur++;
        }
    }

    // Calculate forward interpolation result
    void calculateForwardResult() {
        h = (x[1] - x[0]);
        u = (y - x[0]) / h;
        
        fores = 0.0;
        for(int i = 0; i < n; i++){
            fores += dif[0][i] * recur(i, u);
        }
        forward_calculated = true;
    }

    // Calculate backward interpolation result
    void calculateBackwardResult() {
        h = (x[1] - x[0]);
        u = (y - x[n - 1]) / h;
    
        backres = 0.0;
        for(int i = 0; i < n; i++){
            backres += bif[n - 1][i] * becur(i, u);
        }
        backward_calculated = true;
    }

public:
    // Constructor
    NewtonInterpolation() : forward_calculated(false), backward_calculated(false) {}

    void inputData(){
        cin >> n;   //Enter number of data points
        cin >> y;   //Enter the value of y to interpolate
        x.assign(n , 0);
        f.assign(n , 0);

        // Enter x and f(x) values
        for(int i = 0; i < n; i++){
            cin >> x[i] >> f[i];
        }
    }
    
    void setData(int n_val, double y_val, vector<double>& x_val, vector<double>& f_val){
        n = n_val;
        y = y_val;
        x = x_val;
        f = f_val;
    }

    //Perform Newton Forward Interpolation
    void newtonForward(){
        calculateForwardDifference();
        calculateForwardResult();
    }

    //Perform Newton Backward Interpolation
    void newtonBackward(){
        calculateBackwardDifference();
        calculateBackwardResult();
    }

    //Display forward difference table
    void showForwardDifferenceTable(){
        cout << "\n=== Forward Difference Table ===\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dif[i][j] != 0 || j == 0){
                    cout << fixed << setprecision(2) << dif[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    
    //Write forward difference table using FileIO
    template<typename FileIOType>
    void writeForwardDifferenceTableToFile(FileIOType& fio){
        fio.printToFile("\n=== Forward Difference Table ===\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dif[i][j] != 0 || j == 0){
                    stringstream ss;
                    ss << fixed << setprecision(2) << dif[i][j] << " ";
                    fio.printToFile(ss.str());
                }
            }
            fio.printToFile("\n");
        }
    }

    //Display backward difference table
    void showBackwardDifferenceTable(){
        cout << "\n=== Backward Difference Table ===\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(bif[i][j] != 0 || j == 0){
                    cout << fixed << setprecision(2) << bif[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    
    //Write backward difference table using FileIO
    template<typename FileIOType>
    void writeBackwardDifferenceTableToFile(FileIOType& fio){
        fio.printToFile("\n=== Backward Difference Table ===\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(bif[i][j] != 0 || j == 0){
                    stringstream ss;
                    ss << fixed << setprecision(2) << bif[i][j] << " ";
                    fio.printToFile(ss.str());
                }
            }
            fio.printToFile("\n");
        }
    }

    // Display forward result
    void showForwardResult(){
        if(!forward_calculated){
            cout << "Forward interpolation not calculated yet!\n";
            return;
        }
        cout << "\n=== Newton Forward Result ===\n";
        cout << "f(" << y << ") = " << fixed << setprecision(2) << fores << endl;
    }
    
    // Write forward result to file
    void writeForwardResult(ofstream& outFile){
        if(!forward_calculated){
            return;
        }
        outFile << "\n=== Newton Forward Result ===\n";
        outFile << "f(" << y << ") = " << fixed << setprecision(2) << fores << endl;
    }
    
    // Write forward result using FileIO
    template<typename FileIOType>
    void writeForwardResultToFile(FileIOType& fio){
        if(!forward_calculated){
            return;
        }
        fio.printToFile("\n=== Newton Forward Result ===\n");
        stringstream ss;
        ss << "f(" << y << ") = " << fixed << setprecision(2) << fores << "\n";
        fio.printToFile(ss.str());
    }

    // Display backward result
    void showBackwardResult(){
        if(!backward_calculated){
            cout << "Backward interpolation not calculated yet!\n";
            return;
        }
        cout << "\n=== Newton Backward Result ===\n";
        cout << "f(" << y << ") = " << fixed << setprecision(6) << backres << endl;
    }
    
    // Write backward result to file
    void writeBackwardResult(ofstream& outFile){
        if(!backward_calculated){
            return;
        }
        outFile << "\n=== Newton Backward Result ===\n";
        outFile << "f(" << y << ") = " << fixed << setprecision(6) << backres << endl;
    }
    
    // Write backward result using FileIO
    template<typename FileIOType>
    void writeBackwardResultToFile(FileIOType& fio){
        if(!backward_calculated){
            return;
        }
        fio.printToFile("\n=== Newton Backward Result ===\n");
        stringstream ss;
        ss << "f(" << y << ") = " << fixed << setprecision(6) << backres << "\n";
        fio.printToFile(ss.str());
    }
};

// File Operation 
class FileIO{
private:
    ifstream in;
    ofstream out;

public:
    FileIO(){}

    bool openInput(const string &filename = "../Input/input.txt"){
        in.open(filename);
        if(!in.is_open()){
            cerr << "Cannot open input file\n";
            return false;
        }
        return true;
    }

    bool openOutput(const string &filename = "../Output/output.txt"){
        out.open(filename);
        if(!out.is_open()){
            cerr << "Cannot open output file\n";
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



// Controling function 
void Netwon_Interpolations_method(){
    FileIO fileio;
    
    // Open input file
    if(!fileio.openInput("../Input/input.txt")){
        return ;
    }
    
    // Open output file
    if(!fileio.openOutput("../Output/output.txt")){
        return ;
    }
    
    NewtonInterpolation newton;

    // Read data from file
    int n;
    double y;
    vector<double> x, f;
    fileio.input() >> n >> y;
    x.resize(n);
    f.resize(n);
    for(int i = 0; i < n; i++){
        fileio.input() >> x[i] >> f[i];
    }
    newton.setData(n, y, x, f);
    
    int mtd_choice;
    cout << "\n=== Select Interpolation Method ===\n";
    cout << "1. Newton Forward Interpolation\n";
    cout << "2. Newton Backward Interpolation\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> mtd_choice;
    
    if(mtd_choice == 1){
        newton.newtonForward();
        
        // Write both table and result to file
        newton.writeForwardDifferenceTableToFile(fileio);
        newton.writeForwardResultToFile(fileio);
        
        while(true){
            int display_choice;
            cout << "\n=== Display Options ===\n";
            cout << "1. Show Difference Table\n";
            cout << "2. Show Result\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> display_choice;
            
            if(display_choice == 1){
                newton.showForwardDifferenceTable();
            } else if(display_choice == 2){
                newton.showForwardResult();
            } else if(display_choice == 3){
                break;
            } else{
                cout << "Invalid choice! Please try again.\n";
            }
        }
        
    } else if(mtd_choice == 2){
        newton.newtonBackward();
        
        // Write both table and result to file
        newton.writeBackwardDifferenceTableToFile(fileio);
        newton.writeBackwardResultToFile(fileio);
        
        while(true){
            int display_choice;
            cout << "\n=== Display Options ===\n";
            cout << "1. Show Difference Table\n";
            cout << "2. Show Result\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> display_choice;
            
            if(display_choice == 1){
                newton.showBackwardDifferenceTable();
            } else if(display_choice == 2){
                newton.showBackwardResult();
            } else if(display_choice == 3){
                break;
            } else {
                cout << "Invalid choice! Please try again.\n";
            }
        }
        
    } else {
        cout << "Invalid choice! Exiting...\n";
        return ;
    }

    cout << "\nThank you for using Newton Interpolation!\n";

    // Cleanup
    fileio.closeFiles();
    return ;
}

int main(){
    cout << "\n === Methods === \n";
    Netwon_Interpolations_method();
}
