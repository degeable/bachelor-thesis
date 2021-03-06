#include "VectorCharacter.h"
void VectorCharacter::generateColon(vector<float> &v)
{
	m (v, 39.555, 1008.5772);
	l (v, 0, -10.98003);
	l (v, 10.89, 0);
	l (v, 0, 10.98003);
	l (v, -10.89, 0);
	z (v);
	m (v, 0, 25.65);
	l (v, 0, -10.98);
	l (v, 10.89, 0);
	l (v, 0, 10.98);
	l (v, -10.89, 0);
	z(v);

}

void VectorCharacter::generateDegree(vector<float> &v)
{
	m (v, 60.705, 984.81717);
	q (v, 0, 3.24, -1.26, 6.12);
	q (v, -1.26, 2.79, -3.42, 4.95);
	q (v, -2.07, 2.16, -4.95, 3.42);
	q (v, -2.88, 1.17003, -6.12, 1.17003);
	q (v, -3.24, 0, -6.12, -1.17003);
	q (v, -2.79, -1.26, -4.95, -3.42);
	q (v, -2.16, -2.16, -3.42, -4.95);
	q (v, -1.17, -2.88, -1.17, -6.12);
	q (v, 0, -3.24, 1.17, -6.12);
	q (v, 1.26, -2.88, 3.42, -4.95);
	q (v, 2.16, -2.16, 4.95, -3.42);
	q (v, 2.88, -1.26, 6.12, -1.26);
	q (v, 3.24, 0, 6.12, 1.26);
	q (v, 2.88, 1.26, 4.95, 3.42);
	q (v, 2.16, 2.07, 3.42, 4.95);
	q (v, 1.26, 2.88, 1.26, 6.12);
	z (v);
	m (v, -7.56, 0);
	q (v, 0, -1.71, -0.63, -3.24);
	q (v, -0.63, -1.53, -1.8, -2.7);
	q (v, -1.08, -1.17, -2.61, -1.8);
	q (v, -1.44, -0.63, -3.15, -0.63);
	q (v, -3.42, 0, -5.76, 2.43);
	q (v, -2.34, 2.43, -2.34, 5.94);
	q (v, 0, 3.51, 2.34, 5.94);
	q (v, 2.34, 2.34, 5.76, 2.34);
	q (v, 3.42, 0, 5.76, -2.34);
	q (v, 2.43, -2.43, 2.43, -5.94);
	z(v);

}

void VectorCharacter::generateDigit0(vector<float> &v)
{
	m (v, 63.540001, 1016.4072);
	q (v, 0, 4.32, -1.53, 7.74);
	q (v, -1.44, 3.33, -3.96, 5.76);
	q (v, -2.52, 2.34, -5.94, 3.6);
	q (v, -3.33, 1.26, -7.11, 1.26);
	q (v, -3.78, 0, -7.2, -1.26);
	q (v, -3.33, -1.26, -5.85, -3.6);
	q (v, -2.52, -2.43, -4.05, -5.76);
	q (v, -1.44, -3.42, -1.44, -7.74);
	l (v, 0, -18.09003);
	q (v, 0, -4.32, 1.44, -7.65);
	q (v, 1.53, -3.42, 4.05, -5.76);
	q (v, 2.52, -2.43, 5.85, -3.69);
	q (v, 3.42, -1.26, 7.2, -1.26);
	q (v, 3.78, 0, 7.11, 1.26);
	q (v, 3.42, 1.26, 5.94, 3.69);
	q (v, 2.52, 2.34, 3.96, 5.76);
	q (v, 1.53, 3.33, 1.53, 7.65);
	l (v, 0, 18.09003);
	z (v);
	m (v, -9.18, -17.82003);
	q (v, 0, -4.68, -2.52, -7.56);
	q (v, -2.43, -2.88, -6.84, -2.88);
	q (v, -4.41, 0, -6.93, 2.88);
	q (v, -2.43, 2.88, -2.43, 7.56);
	l (v, 0, 17.55003);
	q (v, 0, 4.68, 2.43, 7.56);
	q (v, 2.52, 2.88, 6.93, 2.88);
	q (v, 4.41, 0, 6.84, -2.88);
	q (v, 2.52, -2.88, 2.52, -7.56);
	l (v, 0, -17.55003);
	z(v);

}

void VectorCharacter::generateDigit1(vector<float> &v)
{
	m (v, 46.71, 1034.2272);
	l (v, 0, -43.74003);
	l (v, -12.6, 10.98003);
	l (v, 0, -10.17003);
	l (v, 12.6, -10.8);
	l (v, 9.18, 0);
	l (v, 0, 53.73003);
	l (v, -9.18, 0);
	z(v);

}

void VectorCharacter::generateDigit2(vector<float> &v)
{
	m (v, 25.695001, 1034.2272);
	l (v, 0, -8.19);
	l (v, 21.78, -19.8);
	q (v, 2.88, -2.61, 4.5, -5.31);
	q (v, 1.71, -2.70003, 1.71, -5.58003);
	q (v, 0, -3.87, -2.61, -6.39);
	q (v, -2.52, -2.61, -6.66, -2.61);
	q (v, -1.89, 0, -3.6, 0.63);
	q (v, -1.71, 0.63, -3.06, 1.8);
	q (v, -1.26, 1.17, -2.07, 2.97);
	q (v, -0.72, 1.8, -0.72, 4.05);
	l (v, -9.18, 0);
	q (v, 0, -3.96, 1.44, -7.2);
	q (v, 1.44, -3.24, 3.96, -5.58);
	q (v, 2.52, -2.34, 5.85, -3.6);
	q (v, 3.42, -1.26, 7.38, -1.26);
	q (v, 4.05, 0, 7.38, 1.26);
	q (v, 3.42, 1.26, 5.85, 3.6);
	q (v, 2.52, 2.25, 3.87, 5.4);
	q (v, 1.35, 3.06, 1.35, 6.84);
	q (v, 0, 2.52, -0.81, 4.68);
	q (v, -0.72, 2.16003, -2.07, 4.23003);
	q (v, -1.35, 1.98, -3.15, 3.96);
	q (v, -1.8, 1.89, -3.87, 3.87);
	l (v, -14.85, 14.04);
	l (v, 26.19, 0);
	l (v, 0, 8.19);
	l (v, -38.61, 0);
	z(v);

}

void VectorCharacter::generateDigit3(vector<float> &v)
{
	m (v, 64.665001, 1026.5772);
	q (v, 0, 4.59, -1.62, 8.1);
	q (v, -1.53, 3.51, -4.23, 5.85);
	q (v, -2.61, 2.34, -6.21, 3.51);
	q (v, -3.51, 1.17, -7.56, 1.17);
	q (v, -3.87, 0, -7.38, -1.08);
	q (v, -3.51, -0.99, -6.21, -3.24);
	q (v, -2.7, -2.16, -4.41, -5.58);
	q (v, -1.62, -3.33, -1.71, -8.01);
	l (v, 9.18, 0);
	q (v, 0.09, 2.61, 0.99, 4.41);
	q (v, 0.99, 1.8, 2.43, 2.97);
	q (v, 1.44, 1.26, 3.24, 1.8);
	q (v, 1.89, 0.54, 3.87, 0.54);
	q (v, 4.5, 0, 7.47, -2.79);
	q (v, 2.97, -2.7, 2.97, -7.83);
	q (v, 0, -4.86, -2.7, -7.65);
	q (v, -2.7, -2.88, -8.1, -2.88);
	l (v, -1.53, 0);
	l (v, 0, -8.01);
	l (v, 1.53, 0);
	q (v, 5.04, 0, 7.38, -2.7);
	q (v, 2.34, -2.7, 2.34, -7.11003);
	q (v, 0, -4.86, -2.79, -7.38);
	q (v, -2.7, -2.52, -6.66, -2.52);
	q (v, -4.23, 0, -6.75, 2.43);
	q (v, -2.52, 2.43, -2.88, 6.75);
	l (v, -9.18, 0);
	q (v, 0.18, -4.05, 1.71, -7.29);
	q (v, 1.53, -3.24, 4.05, -5.49);
	q (v, 2.52, -2.25, 5.85, -3.42);
	q (v, 3.33, -1.17, 7.2, -1.17);
	q (v, 4.05, 0, 7.47, 1.35);
	q (v, 3.42, 1.26, 5.85, 3.69);
	q (v, 2.52, 2.34, 3.87, 5.67);
	q (v, 1.44, 3.24, 1.44, 7.2);
	q (v, 0, 5.13003, -2.07, 8.55003);
	q (v, -2.07, 3.33, -5.85, 5.13);
	q (v, 4.14, 1.8, 6.57, 5.49);
	q (v, 2.43, 3.6, 2.43, 9.54);
	z(v);

}

void VectorCharacter::generateDigit4(vector<float> &v)
{
	m (v, 59.309999, 1031.5272);
	l (v, 0, 13.77);
	l (v, -8.82, 0);
	l (v, 0, -13.77);
	l (v, -27.45, 0);
	l (v, 0, -8.55);
	l (v, 22.77, -45.90003);
	l (v, 9.81, 0);
	l (v, -22.77, 45.90003);
	l (v, 17.64, 0);
	l (v, 0, -15.84);
	l (v, 8.82, 0);
	l (v, 0, 15.84);
	l (v, 7.65, 0);
	l (v, 0, 8.55);
	l (v, -7.65, 0);
	z(v);

}

void VectorCharacter::generateDigit5(vector<float> &v)
{
	m (v, 63.720001, 1023.1572);
	q (v, 0, 5.13, -0.99, 9.36);
	q (v, -0.9, 4.14, -4.41, 7.65);
	q (v, -2.16, 2.16, -5.49, 3.6);
	q (v, -3.33, 1.44, -8.01, 1.44);
	q (v, -4.59, 0, -8.1, -1.44);
	q (v, -3.42, -1.44, -5.49, -3.51);
	q (v, -2.61, -2.61, -3.69, -5.76);
	q (v, -0.99, -3.06, -1.26, -6.48);
	l (v, 9.18, 0);
	q (v, 0.54, 4.32, 2.79, 6.57);
	q (v, 2.25, 2.34, 6.57, 2.34);
	q (v, 4.23, 0, 6.75, -2.52);
	q (v, 2.07, -2.07, 2.52, -5.04);
	q (v, 0.45, -2.97, 0.45, -6.21);
	q (v, 0, -2.88, -0.45, -5.31);
	q (v, -0.36, -2.43, -1.44, -4.23);
	q (v, -0.99, -1.8, -2.79, -2.79);
	q (v, -1.8, -1.08, -4.59, -1.08);
	q (v, -3.96, 0, -6.21, 1.71);
	q (v, -2.25, 1.71, -2.97, 4.05);
	l (v, -8.28, 0);
	l (v, 0, -35.01003);
	l (v, 34.47, 0);
	l (v, 0, 8.19);
	l (v, -26.19, 0);
	l (v, 0, 16.92003);
	q (v, 1.62, -1.71, 4.32, -2.7);
	q (v, 2.7, -0.99, 6.21, -0.99);
	q (v, 3.78, 0, 6.66, 1.08);
	q (v, 2.88, 1.08, 4.86, 3.06);
	q (v, 1.8, 1.8, 2.88, 3.87);
	q (v, 1.17, 2.07, 1.71, 4.23);
	q (v, 0.63, 2.16, 0.81, 4.5);
	q (v, 0.18, 2.25, 0.18, 4.5);
	z(v);

}

void VectorCharacter::generateDigit6(vector<float> &v)
{
	m (v, 65.070001, 1014.1572);
	q (v, 0, 4.68, -1.53, 8.55);
	q (v, -1.44, 3.78, -4.14, 6.48);
	q (v, -2.61, 2.7, -6.3, 4.14);
	q (v, -3.69, 1.44, -8.1, 1.44);
	q (v, -4.41, 0, -8.1, -1.35);
	q (v, -3.69, -1.44, -6.39, -3.96);
	q (v, -2.61, -2.61, -4.14, -6.3);
	q (v, -1.44, -3.78, -1.44, -8.55);
	q (v, 0, -4.86, 1.35, -9.09);
	q (v, 1.35, -4.32, 4.14, -9.27003);
	l (v, 15.39, -27.54);
	l (v, 9.81, 0);
	l (v, -15.75, 27.27);
	q (v, 1.71, -0.9, 3.42, -1.17);
	q (v, 1.71, -0.36, 3.96, -0.36);
	q (v, 3.78, 0, 7.02, 1.35);
	q (v, 3.33, 1.35, 5.67, 3.96);
	q (v, 2.43, 2.52003, 3.78, 6.21003);
	q (v, 1.35, 3.6, 1.35, 8.19);
	z (v);
	m (v, -9.18, 0.27);
	q (v, 0, -2.61, -0.72, -4.86);
	q (v, -0.72, -2.34, -2.16, -3.96);
	q (v, -1.44, -1.71, -3.51, -2.7);
	q (v, -1.98, -0.99, -4.5, -0.99);
	q (v, -4.86, 0, -7.92, 3.42);
	q (v, -2.97, 3.33, -2.97, 9.09);
	q (v, 0, 5.76, 2.97, 9.09);
	q (v, 3.06, 3.33, 7.92, 3.33);
	q (v, 4.86, 0, 7.83, -3.33);
	q (v, 3.06, -3.33, 3.06, -9.09);
	z(v);

}

void VectorCharacter::generateDigit7(vector<float> &v)
{
	m (v, 40.320001, 1045.0272);
	l (v, -9.81, 0);
	l (v, 24.84, -56.34003);
	l (v, -21.69, 0);
	l (v, 0, 10.08);
	l (v, -8.82, 0);
	l (v, 0, -18.27);
	l (v, 40.32, 0);
	l (v, 0, 8.19);
	l (v, -24.84, 56.34003);
	z(v);

}

void VectorCharacter::generateDigit8(vector<float> &v)
{
	m (v, 64.754998, 1016.1372);
	q (v, 0, 4.32, -1.53, 7.83);
	q (v, -1.53, 3.42, -4.23, 5.85);
	q (v, -2.7, 2.43, -6.3, 3.69);
	q (v, -3.6, 1.26, -7.74, 1.26);
	q (v, -4.14, 0, -7.74, -1.26);
	q (v, -3.6, -1.26, -6.3, -3.69);
	q (v, -2.61, -2.43, -4.14, -5.85);
	q (v, -1.53, -3.51, -1.53, -7.83);
	q (v, 0, -2.88, 0.72, -5.22);
	q (v, 0.81, -2.34, 1.98, -4.14);
	q (v, 1.26, -1.89, 2.79, -3.24);
	q (v, 1.62, -1.44, 3.33, -2.43);
	q (v, -3.15, -1.89003, -5.49, -5.22003);
	q (v, -2.34, -3.42, -2.34, -8.55);
	q (v, 0, -4.05, 1.44, -7.29);
	q (v, 1.44, -3.24, 3.96, -5.58);
	q (v, 2.61, -2.34, 5.94, -3.6);
	q (v, 3.42, -1.26, 7.38, -1.26);
	q (v, 3.87, 0, 7.29, 1.26);
	q (v, 3.42, 1.26, 5.94, 3.6);
	q (v, 2.61, 2.34, 4.05, 5.58);
	q (v, 1.44, 3.24, 1.44, 7.29);
	q (v, 0, 5.13, -2.34, 8.55);
	q (v, -2.25, 3.33, -5.4, 5.22003);
	q (v, 1.71, 0.99, 3.24, 2.43);
	q (v, 1.62, 1.35, 2.79, 3.24);
	q (v, 1.26, 1.8, 1.98, 4.14);
	q (v, 0.81, 2.34, 0.81, 5.22);
	z (v);
	m (v, -9.18, -0.18);
	q (v, 0, -2.25, -0.81, -4.14);
	q (v, -0.81, -1.98, -2.25, -3.42);
	q (v, -1.44, -1.44, -3.42, -2.25);
	q (v, -1.89, -0.9, -4.14, -0.9);
	q (v, -2.25, 0, -4.23, 0.9);
	q (v, -1.89, 0.81, -3.33, 2.25);
	q (v, -1.35, 1.44, -2.16, 3.42);
	q (v, -0.81, 1.89, -0.81, 4.14);
	q (v, 0, 2.25, 0.81, 4.23);
	q (v, 0.81, 1.89, 2.16, 3.33);
	q (v, 1.44, 1.44, 3.33, 2.25);
	q (v, 1.98, 0.81, 4.23, 0.81);
	q (v, 2.25, 0, 4.14, -0.81);
	q (v, 1.98, -0.81, 3.42, -2.25);
	q (v, 1.44, -1.44, 2.25, -3.33);
	q (v, 0.81, -1.98, 0.81, -4.23);
	z (v);
	m (v, -1.08, -28.35003);
	q (v, 0, -4.23, -2.7, -7.02);
	q (v, -2.61, -2.79, -6.84, -2.79);
	q (v, -4.23, 0, -6.93, 2.79);
	q (v, -2.61, 2.79, -2.61, 7.02);
	q (v, 0, 4.32, 2.61, 7.02);
	q (v, 2.7, 2.7, 6.93, 2.7);
	q (v, 4.23, 0, 6.84, -2.7);
	q (v, 2.7, -2.7, 2.7, -7.02);
	z(v);

}

void VectorCharacter::generateDigit9(vector<float> &v)
{
	m (v, 65.070001, 1000.1172);
	q (v, 0, 4.86, -1.35, 9.18);
	q (v, -1.26, 4.23, -4.05, 9.18);
	l (v, -15.48, 27.54);
	l (v, -9.81, 0);
	l (v, 15.75, -27.27);
	q (v, -1.71, 0.9, -3.42, 1.26);
	q (v, -1.62, 0.27, -3.87, 0.27);
	q (v, -3.78, 0, -7.11, -1.35);
	q (v, -3.24, -1.35, -5.67, -3.87);
	q (v, -2.43, -2.61, -3.78, -6.21);
	q (v, -1.35, -3.69, -1.35, -8.28);
	q (v, 0, -4.68003, 1.44, -8.46003);
	q (v, 1.53, -3.87, 4.14, -6.57);
	q (v, 2.7, -2.7, 6.39, -4.14);
	q (v, 3.69, -1.44, 8.1, -1.44);
	q (v, 4.41, 0, 8.1, 1.44);
	q (v, 3.69, 1.35, 6.3, 3.96);
	q (v, 2.7, 2.52, 4.14, 6.3);
	q (v, 1.53, 3.78, 1.53, 8.46003);
	z (v);
	m (v, -9.18, 0.18);
	q (v, 0, -5.76003, -3.06, -9.09003);
	q (v, -2.97, -3.33, -7.83, -3.33);
	q (v, -4.86, 0, -7.92, 3.33);
	q (v, -2.97, 3.33, -2.97, 9.09003);
	q (v, 0, 2.61, 0.72, 4.95);
	q (v, 0.72, 2.25, 2.16, 3.96);
	q (v, 1.44, 1.71, 3.42, 2.7);
	q (v, 1.98, 0.9, 4.59, 0.9);
	q (v, 4.86, 0, 7.83, -3.33);
	q (v, 3.06, -3.42, 3.06, -9.18);
	z(v);

}

void VectorCharacter::generateLowerCaseAM(vector<float> &v)
{
	m (v, 15.501094, 1034.2272);
	l (v, 0, -4.14);
	q (v, -2.52, 2.52, -5.22, 3.6);
	q (v, -2.6999998, 1.08, -6.9299998, 1.08);
	q (v, -4.31999999, 0, -7.29, -0.99);
	q (v, -2.88, -1.08, -4.95, -3.15);
	q (v, -3.6000002, -3.78, -3.6000002, -9.81);
	q (v, 0, -5.76, 3.8700002, -9.45);
	q (v, 3.96, -3.69, 11.88, -3.69);
	l (v, 12.0599998, 0);
	l (v, 0, -3.24);
	q (v, 0, -4.32, -2.34, -6.39003);
	q (v, -2.25, -2.16, -7.6499998, -2.16);
	q (v, -3.78, 0, -5.93999999, 0.99);
	q (v, -2.16000001, 0.99, -4.05000001, 3.42003);
	l (v, -6.0300002, -5.67003);
	q (v, 3.2400002, -3.78, 6.9300002, -5.13);
	q (v, 3.78000001, -1.44, 9.45, -1.44);
	q (v, 18.8099998, 0, 18.8099998, 15.66003);
	l (v, 0, 30.51);
	l (v, -9, 0);
	z (v);
	m (v, -0.18, -20.16);
	l (v, -10.7099998, 0);
	q (v, -4.04999999, 0, -6.12, 1.71);
	q (v, -2.07, 1.71, -2.07, 4.86);
	q (v, 0, 3.15, 1.98, 4.86);
	q (v, 2.07000001, 1.62, 6.39, 1.62);
	q (v, 2.61, 0, 4.68, -0.36);
	q (v, 2.0699998, -0.45, 3.8699998, -2.25);
	q (v, 1.98, -1.98, 1.98, -6.75);
	l (v, 0, -3.69);
	z(v);

	cx=0;cy=0;

	m (v, 93.308907, 1034.2272);
	l (v, 0, -27.81);
	q (v, 0, -5.31, -2.7, -7.74003);
	q (v, -2.61, -2.43, -6.48, -2.43);
	q (v, -1.89, 0, -3.6, 0.63);
	q (v, -1.71, 0.54, -3.06, 1.8);
	q (v, -1.26, 1.17, -2.07, 3.06003);
	q (v, -0.72, 1.8, -0.72, 4.23);
	l (v, 0, 28.26);
	l (v, -9.18, 0);
	l (v, 0, -27.81);
	q (v, 0, -5.31, -2.7, -7.74003);
	q (v, -2.61, -2.43, -6.48, -2.43);
	q (v, -3.87, 0, -6.66, 2.52);
	q (v, -2.79, 2.43003, -2.79, 7.65003);
	l (v, 0, 27.81);
	l (v, -9.18, 0);
	l (v, 0, -45.63003);
	l (v, 9, 0);
	l (v, 0, 4.59);
	q (v, 2.34, -2.52, 5.49, -3.78);
	q (v, 3.24, -1.35, 6.66, -1.35);
	q (v, 8.64, 0, 12.96, 6.66);
	q (v, 5.49, -6.66, 14.31, -6.66);
	q (v, 3.51, 0, 6.48, 1.08);
	q (v, 2.97, 1.08, 5.04, 3.06);
	q (v, 2.610003, 2.61, 3.690003, 5.85);
	q (v, 1.17, 3.15003, 1.17, 7.02003);
	l (v, 0, 29.16);
	l (v, -9.180003, 0);
	z(v);

}

void VectorCharacter::generateLowerCasePM(vector<float> &v)
{
	m (v, 25.516408, 1011.3672);
	q (v, 0, 2.61, -0.18, 5.31);
	q (v, -0.09, 2.7, -0.63, 5.31);
	q (v, -0.54, 2.52, -1.62, 4.77);
	q (v, -0.99, 2.25, -2.7, 3.96);
	q (v, -1.89, 1.89, -4.77, 2.97);
	q (v, -2.88, 1.08, -6.3000004, 1.08);
	q (v, -3.69, 0, -6.57, -1.08);
	q (v, -2.87999998, -1.17, -5.4, -4.14);
	l (v, 0, 23.13);
	l (v, -9.1799996, 0);
	l (v, 0, -64.08003);
	l (v, 8.9999996, 0);
	l (v, 0, 4.86);
	q (v, 2.61000002, -3.15, 5.4, -4.23);
	q (v, 2.88, -1.17, 6.66, -1.17);
	q (v, 3.4200004, 0, 6.3000004, 1.08);
	q (v, 2.97, 1.08, 4.86, 2.97);
	q (v, 1.71, 1.71, 2.7, 3.96);
	q (v, 1.08, 2.25, 1.62, 4.77003);
	q (v, 0.54, 2.52, 0.63, 5.22);
	q (v, 0.18, 2.7, 0.18, 5.31);
	z (v);
	m (v, -9.18, 0);
	q (v, 0, -3.06, -0.36, -5.76);
	q (v, -0.27, -2.79, -1.26, -4.86);
	q (v, -0.99, -2.07003, -2.88, -3.24003);
	q (v, -1.8900004, -1.26, -4.9500004, -1.26);
	q (v, -3.15, 0, -5.04, 1.26);
	q (v, -1.79999998, 1.17, -2.88, 3.24003);
	q (v, -0.99, 2.07, -1.35, 4.86);
	q (v, -0.27, 2.7, -0.27, 5.76);
	q (v, 0, 3.06, 0.27, 5.85);
	q (v, 0.36, 2.7, 1.35, 4.86);
	q (v, 1.08000002, 2.07, 2.88, 3.33);
	q (v, 1.89, 1.17, 5.04, 1.17);
	q (v, 3.06, 0, 4.9500004, -1.17);
	q (v, 1.89, -1.26, 2.88, -3.33);
	q (v, 0.99, -2.16, 1.26, -4.86);
	q (v, 0.36, -2.79, 0.36, -5.85);
	z(v);

	cx=0;cy=0;

	m (v, 92.653595, 1034.2272);
	l (v, 0, -27.81);
	q (v, 0, -5.31, -2.7, -7.74003);
	q (v, -2.61, -2.43, -6.48, -2.43);
	q (v, -1.89, 0, -3.6, 0.63);
	q (v, -1.71, 0.54, -3.06, 1.8);
	q (v, -1.26, 1.17, -2.07, 3.06003);
	q (v, -0.72, 1.8, -0.72, 4.23);
	l (v, 0, 28.26);
	l (v, -9.18, 0);
	l (v, 0, -27.81);
	q (v, 0, -5.31, -2.7, -7.74003);
	q (v, -2.61, -2.43, -6.48, -2.43);
	q (v, -3.87, 0, -6.66, 2.52);
	q (v, -2.79, 2.43003, -2.79, 7.65003);
	l (v, 0, 27.81);
	l (v, -9.18, 0);
	l (v, 0, -45.63003);
	l (v, 9, 0);
	l (v, 0, 4.59);
	q (v, 2.34, -2.52, 5.49, -3.78);
	q (v, 3.24, -1.35, 6.66, -1.35);
	q (v, 8.64, 0, 12.96, 6.66);
	q (v, 5.49, -6.66, 14.31, -6.66);
	q (v, 3.51, 0, 6.48, 1.08);
	q (v, 2.97, 1.08, 5.04, 3.06);
	q (v, 2.61, 2.61, 3.690005, 5.85);
	q (v, 1.17, 3.15003, 1.17, 7.02003);
	l (v, 0, 29.16);
	l (v, -9.180005, 0);
	z(v);

}

void VectorCharacter::generateMinus(vector<float> &v)
{
	m (v, 31.860002, 1013.5272);
	l (v, 0, -8.55);
	l (v, 26.28, 0);
	l (v, 0, 8.55);
	l (v, -26.28, 0);
	z(v);

}

void VectorCharacter::generatePercent(vector<float> &v)
{
	m (v, 77.670001, 1022.5272);
	q (v, 0, 2.88, -0.99, 5.22);
	q (v, -0.99, 2.25, -2.7, 3.87);
	q (v, -1.71, 1.53, -4.05, 2.43);
	q (v, -2.25, 0.81, -4.86, 0.81);
	q (v, -2.61, 0, -4.95, -0.81);
	q (v, -2.25, -0.9, -3.96, -2.43);
	q (v, -1.71, -1.62, -2.7, -3.87);
	q (v, -0.99, -2.34, -0.99, -5.22);
	l (v, 0, -9.09);
	q (v, 0, -2.88, 0.99, -5.13);
	q (v, 0.99, -2.34, 2.7, -3.87);
	q (v, 1.71, -1.62, 3.96, -2.43);
	q (v, 2.34, -0.9, 4.95, -0.9);
	q (v, 2.61, 0, 4.86, 0.9);
	q (v, 2.34, 0.81, 4.05, 2.43);
	q (v, 1.71, 1.53, 2.7, 3.87);
	q (v, 0.99, 2.25, 0.99, 5.13);
	l (v, 0, 9.09);
	z (v);
	m (v, -40.14, -31.50003);
	q (v, 0, 2.88, -0.99, 5.22);
	q (v, -0.99, 2.25, -2.7, 3.87003);
	q (v, -1.71, 1.53, -4.05, 2.34);
	q (v, -2.25, 0.81, -4.86, 0.81);
	q (v, -2.61, 0, -4.95, -0.81);
	q (v, -2.25, -0.81, -3.96, -2.34);
	q (v, -1.71, -1.62003, -2.7, -3.87003);
	q (v, -0.99, -2.34, -0.99, -5.22);
	l (v, 0, -9.18);
	q (v, 0, -2.88, 0.99, -5.13);
	q (v, 0.99, -2.34, 2.7, -3.87);
	q (v, 1.71, -1.62, 3.96, -2.43);
	q (v, 2.34, -0.9, 4.95, -0.9);
	q (v, 2.61, 0, 4.86, 0.9);
	q (v, 2.34, 0.81, 4.05, 2.43);
	q (v, 1.71, 1.53, 2.7, 3.87);
	q (v, 0.99, 2.25, 0.99, 5.13);
	l (v, 0, 9.18);
	z (v);
	m (v, -3.96, 43.20003);
	l (v, -7.38, 0);
	l (v, 30.24, -64.08003);
	l (v, 7.29, 0);
	l (v, -30.15, 64.08003);
	z (v);
	m (v, 37.17, -20.52);
	q (v, 0, -3.06, -1.44, -4.77);
	q (v, -1.35, -1.71, -4.23, -1.71);
	q (v, -2.88, 0, -4.32, 1.71);
	q (v, -1.35, 1.62, -1.35, 4.77);
	l (v, 0, 8.55);
	q (v, 0, 3.15, 1.35, 4.86);
	q (v, 1.44, 1.62, 4.32, 1.62);
	q (v, 2.88, 0, 4.23, -1.71);
	q (v, 1.44, -1.71, 1.44, -4.77);
	l (v, 0, -8.55);
	z (v);
	m (v, -40.14, -31.59003);
	q (v, 0, -3.06, -1.44, -4.77);
	q (v, -1.35, -1.71, -4.23, -1.71);
	q (v, -2.88, 0, -4.32, 1.71);
	q (v, -1.35, 1.62, -1.35, 4.77);
	l (v, 0, 8.64);
	q (v, 0, 6.39, 5.67, 6.39);
	q (v, 2.88, 0, 4.23, -1.62);
	q (v, 1.44, -1.71, 1.44, -4.77);
	l (v, 0, -8.64);
	z(v);

}

void VectorCharacter::generatePlus(vector<float> &v)
{
	m (v, 49.274999, 1013.9772);
	l (v, 0, 15.12);
	l (v, -8.55, 0);
	l (v, 0, -15.12);
	l (v, -15.12, 0);
	l (v, 0, -8.55);
	l (v, 15.12, 0);
	l (v, 0, -15.03003);
	l (v, 8.55, 0);
	l (v, 0, 15.03003);
	l (v, 15.12, 0);
	l (v, 0, 8.55);
	l (v, -15.12, 0);
	z(v);

}

void VectorCharacter::generatePoint(vector<float> &v)
{
	m (v, 39.510002, 1034.2272);
	l (v, 0, -10.98);
	l (v, 10.98, 0);
	l (v, 0, 10.98);
	l (v, -10.98, 0);
	z(v);

}

void VectorCharacter::generateUpperCaseAM(vector<float> &v)
{
	m (v, 29.689453, 1034.2272);
	l (v, -4.41, -12.87);
	l (v, -25.29000018, 0);
	l (v, -4.41000002, 12.87);
	l (v, -10.3499998, 0);
	l (v, 23.4899998, -64.08003);
	l (v, 7.8300002, 0);
	l (v, 23.49, 64.08003);
	l (v, -10.35, 0);
	z (v);
	m (v, -16.83, -49.59003);
	l (v, -9.9900002, 28.44003);
	l (v, 19.7100002, 0);
	l (v, -9.72, -28.44003);
	z(v);

	cx=0;cy=0;

	m (v, 95.050547, 1034.2272);
	l (v, 0, -42.84003);
	l (v, -14.76, 31.23003);
	l (v, -7.2, 0);
	l (v, -15.12, -31.23003);
	l (v, 0, 42.84003);
	l (v, -9.72, 0);
	l (v, 0, -64.08003);
	l (v, 9.72, 0);
	l (v, 18.72, 39.87003);
	l (v, 18.36, -39.87003);
	l (v, 9.720003, 0);
	l (v, 0, 64.08003);
	l (v, -9.720003, 0);
	z(v);

}

void VectorCharacter::generateUpperCasePM(vector<float> &v)
{
	m (v, 33.698671, 989.58717);
	q (v, 0, 4.23, -1.44, 7.83);
	q (v, -1.44, 3.51003, -4.14, 6.12003);
	q (v, -2.7, 2.52, -6.48, 4.05);
	q (v, -3.78, 1.44, -8.46, 1.44);
	l (v, -14.5800002, 0);
	l (v, 0, 25.2);
	l (v, -9.7199998, 0);
	l (v, 0, -64.08003);
	l (v, 24.3, 0);
	q (v, 4.68, 0, 8.46, 1.53);
	q (v, 3.78, 1.44, 6.48, 4.05);
	q (v, 2.7, 2.52, 4.14, 6.12);
	q (v, 1.44, 3.6, 1.44, 7.74);
	z (v);
	m (v, -9.72, 0);
	q (v, 0, -5.13, -3.15, -7.92);
	q (v, -3.06, -2.79, -8.19, -2.79);
	l (v, -14.0400002, 0);
	l (v, 0, 21.33003);
	l (v, 14.0400002, 0);
	q (v, 5.13, 0, 8.19, -2.70003);
	q (v, 3.15, -2.79, 3.15, -7.92);
	z(v);

	cx=0;cy=0;

	m (v, 91.401327, 1034.2272);
	l (v, 0, -42.84003);
	l (v, -14.76, 31.23003);
	l (v, -7.2, 0);
	l (v, -15.12, -31.23003);
	l (v, 0, 42.84003);
	l (v, -9.72, 0);
	l (v, 0, -64.08003);
	l (v, 9.72, 0);
	l (v, 18.72, 39.87003);
	l (v, 18.36, -39.87003);
	l (v, 9.720003, 0);
	l (v, 0, 64.08003);
	l (v, -9.720003, 0);
	z(v);

}

