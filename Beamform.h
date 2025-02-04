#ifndef _BEAMFORM_H_
#define _BEAMFORM_H_
#include<vector>

using namespace std;

#include "Matrix.h"
#include "Dtype.h"
#include "PARAM.h"
#include "fft.h"




class Beamform {
private:
  unsigned n, type, noise_type; //n:number of sensor, type :DBS of Fixed, noise_type: AWGN or OFDM
  double d, f, c, fs, theta ; // distance, frequency, speed, sampling freq, theta estimation
  vector<vector<signal_t>> sgn; //2d n x len signal used for beamforming
  bool DoA;// direction estimation
  double estimate_DoA(); //estimate direction of source signal
  vector<vector<complex<double>>> get_weight(vector<double> F_vec, int Type); // weight calculation function
public:
  vector<signal_t> sgn_1d_origin , sgn_beamformed; // original signal for simulation, beamformed result
  Beamform();
  ~Beamform();
  Beamform(unsigned m_n);
  void get_signal(double s_theta, double n_theta, double snr); // setting input signal for simulation
  void status();  //show variables of class
  vector<double> beamform_Rx( ); //beamforming receive
  vector<vector<double>> beamform_Tx(); // beamforming transimission


};




#endif
