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

static double sigmoid(double z) {
    return 1.0 / (1.0+exp(-z));
}

static double sigmoid_prime(double z) {
    return sigmoid(z)*(1-sigmoid(z));
}

static void sigmoid_vector(double *vec, size_t size, double *result) {
    for(int i=0; i < size; ++i) {
        result[i] = sigmoid(vec[i]);
    }
}

static void sigmoid_prime_vector(double *vec, size_t size, double *result) {
    for(int i=0; i < size; ++i) {
        result[i] = sigmoid_prime(vec[i]);
    }
} 
/*
static double *dot_product(double *a, double *b) {
    // TODO
    double res[2] = {0.0, 0.0};
    return res;
}*/


class Network {

    public:
        double *biases[LAYERS-1]; 
        double *weights[LAYERS-1];

        Network() {
            init_weights();
            init_biases();
        }

        /*double feedforward(double *input) {
            for(int i=0; i < LAYERS; ++i) {
                double *b = biases[i];
                double *w = weights[i];
                double res[SIZES[i]];

                double dot_product = dot_product(w, input);

                for(int j=0; j < SIZES[i + 1]; ++j) { 
                    res[j] = dot_product + b[j];
                }

                input = sigmoid(res);
            }
            return input;
        }*/

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

