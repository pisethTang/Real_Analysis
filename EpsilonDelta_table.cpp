#include <cmath>
#include <iostream>
#include <time.h> 
#include <iomanip>


auto terroo = [](const char* s){
        std::cout << s << std::endl;   
}; 

auto f = [](int n){
    return double((3*double(n) + 1))/double((7*double(n) - 4));
};


auto difference = [](int n){
    return f(n) - double(3)/double(7);
};

auto less_than = [](double abs_diff, double epsilon){
    return std::abs(abs_diff) < epsilon;
};

auto epsilon_N = [](double epsilon){
    return std::floor(double(21)/ double(19) * double(1)/double(epsilon)) + 1;
};



void Computation_Table(double epsilon){
    int N = epsilon_N(epsilon);
    std::cout << "Epsilon = "  
              << epsilon
              << " ==> "
              << "N = " 
              << N << "." 
    << std::endl;
    
    
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Epsilon = " << epsilon << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::setw(3) << "n" 
              << std::setw(20) << "s_n" 
              << std::setw(20) << "|s_n - 3/7|" 
              << std::setw(26) << "|s_n - 3/7| < epsilon"
              << std::endl;
    
    
    for (int i=N; i <= N + 100; i++){
        // std::cout << i << "\t" << f(i) << "\t\t" << f_1(i) << std::endl;
        double s_n = f(i);
        double diff = difference(i);
        bool check = less_than(diff, epsilon);
        std::cout << std::setw(3) << i
                  << std::setw(20) <<  std::fixed << std::setprecision(10) << s_n
                  << std::setw(20) << std::fixed << std::setprecision(10) << diff 
                  << std::setw(20) << std::fixed << std::setprecision(10) << check
         << std::endl;
    }
    std::cout << "..." << std::endl;
    

}



int main(int argc, char** argv){    
    double epsilon = 0.0001;
    // terroo("I \u2764 Lambda!\n");
    // std::cout << "n\ts_n\t\t|s_n - 3/7|" << std::endl;
    Computation_Table(epsilon);

    
    return 0;
}