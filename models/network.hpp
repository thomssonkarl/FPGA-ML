// Network.c
//
//
//
#include <random>
#include <iostream>
#include <math.h>
#define LAYERS 3


int SIZES[3] = {2,3,1};


using namespace std;

static double f_rand(double f_min, double f_max) {
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}

static double *sigmoid(double *z) {
    // TODO
    return 1.0 / (1.0 + exp(-z));
}

static double *sigmoid_prime(double *z) {
    // TODO
    return sigmoid(z)*(1-sigmoid(z));
}

static double *dot_product(double *a, double *b) {
    // TODO
    double res[2] = {0.0, 0.0};
    return res;
}

class Network {
    public:
        double *biases[LAYERS-1]; 
        double *weights[LAYERS-1];

        Network() {
            for(int i=0; i < LAYERS-1; ++i) {
                for(int j=0; j < SIZES[i]; ++j) {
                    weights[i][j] = f_rand(SIZES[i], SIZES[i+1]);
                }
            }
            for(int i=1; i < LAYERS; ++i) {
                for(int j=0; j < SIZES[i]; ++j) {
                    biases[i][j] = f_rand(SIZES[i],1);
                }
            }
        }

        double feedforward(double *input) {
            for(int i=0; i < LAYERS; ++i) {
                double *b = biases[i];
                double *w = weights[i];
                double res[SIZES[i]];

                double dot_product = dot_product(w, input);
                
                for(int j=0; j < SIZES[i + 1]; ++j) { //wrap SIZES?
                    res[j] = dot_product + b[j];
                }

                input = sigmoid(res);
            }
            return input;
        }

        void show() {
            cout << "Weights: " << endl;
            for(int i=0; i < LAYERS-1; ++i) {
                for(int j=0; j < SIZES[i]; ++j) {
                    cout << weights[i][j] << ", ";
                }
                cout << endl;
            }
            cout << "Biases: " << endl;
            for(int i=1; i < LAYERS; ++i) {
                for(int j=0; j < SIZES[i]; ++j) {
                    cout << biases[i][j] << ", ";
                }
                cout << endl;
            }
        }
};

