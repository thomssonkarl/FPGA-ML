#include <random>
#include <iostream>
#include <math.h>

using namespace std;

#define LAYERS 3

int SIZES[3] = {2,3,1};

static double f_rand(double f_min, double f_max) {
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}

double sigmoid(double z) {
    return 1.0 / (1.0+exp(-z));
}

double sigmoid_prime(double z) {
    return sigmoid(z)*(1-sigmoid(z));
}

void sigmoid_vector(double *vec, size_t size, double *result) {
    for(int i=0; i < size; ++i) {
        result[i] = sigmoid(vec[i]);
    }
}

void sigmoid_prime_vector(double *vec, size_t size, double *result) {
    for(int i=0; i < size; ++i) {
        result[i] = sigmoid_prime(vec[i]);
    }
} 

double dot_product(double *a, double *b, size_t size) {
    double result = 0.0;
    for(int i=0; i < size; ++i) {
        result += a[i] * b[i]; 
    }
    return result;
}


class Network {

    public:
        double *biases[LAYERS-1]; 
        double *weights[LAYERS-1];

        Network() {
            init_weights();
            init_biases();
        }

        double *feedforward(double *a) {
            for(int i=0; i < LAYERS; ++i) {
                double *b = biases[i];
                double *w = weights[i];
                double res[SIZES[i]];
                // TODO: size of these vectors?
                double dp = dot_product(w, a, SIZES[i+1]); 

                for(int j=0; j < SIZES[i+1]; ++j) { 
                    res[j] = dp + b[j];
                }
                // TODO: Size is probably wrong
                sigmoid_vector(res, SIZES[i], a);
            }
            return a;
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

    private:
        void init_biases() {
            for(int i=1; i < LAYERS; ++i) {
                for(int j=0; j < SIZES[i]; ++j) {
                    biases[i][j] = f_rand(SIZES[i],1);
                }
            }
        }

        void init_weights() {
            for(int i=0; i < LAYERS-1; ++i) {
                for(int j=0; j < SIZES[i]; ++j) {
                    weights[i][j] = f_rand(SIZES[i], SIZES[i+1]);
                }
            }
        }
};

