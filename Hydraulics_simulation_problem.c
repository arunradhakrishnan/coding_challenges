#include <stdio.h>
#include <math.h>

// P= pressure
// Q = mass flow rate 
// V = Volume
// G Conducatance
// t = time
// b = bulk modulus

//


// Parameter |   Value at t=0
// V1 (accumulator) 100
// P1               1000

// V2 (cylinder)    1
// P2               0

// V3 (tank)        ∞
// P3               0

// G1 (fill valve)  0
// G2 (drain valve) 0
// β                10
void main()
{
int V1 = 100; // (accumulator)
double P1 = 1000;

int V2 = 1; //(cylinder)
double P2 = 0;

int V3 =  __INT32_MAX__;//(tank) 
double P3 = 0;

int G1 = 0; //(fill valve)
int G2 = 0; //(drain valve)
int B = 10;

int Q1;
int Q2;

// 5. The program shall calculate the mass flow rate for each orifice based on Equation 1.
// Equation 1
// Q = G × (Pa − Pb)


// 6. The program shall calculate the rate of change in pressure of each volume element based on Equation 2.
// Equation 2
// ΔP/Δt = β/V * ∑ Qi

// 7. The program shall calculate the pressure of each volume element based on Equation 3.
// Equation 3
// Pt + Δt = Pt + Δt *(ΔP/Δt)

// 8. The program shall calculate the pressure of each volume element at discrete points in time starting at time t = 0
// and ending at time t = 10 separated by the time interval Δt = 0.01.


// 9. The program shall output the time and pressure values P1 and P2 in order from smallest to largest time to the C
// standard output (stdout) using the following printf format:
// "%6.2f: accumulator %.5f cylinder %.5f\n", time, P1, P2

// Event Name Time Action
// fill_on 1.0 Set G1 to 1
// fill_off 4.0 Set G1 to 0
// drain_on 8.0 Set G2 to 1

    float end_time = 10.00; 
    float time = 0.00; 


    float Pprev_P1 = 0;
    float Pcurr_P1 = 0;
    float Pnext_P1 = 0;

    float Pprev_P2 = 0;
    float Pcurr_P2 = 0;
    float Pnext_P2 = 0;

    float Pprev_P3 = 0;
    float Pcurr_P3 = 0;
    float Pnext_P3 = 0;


    while(time < 10 )
    {

        //printf("time = %f , %d\n", time, (int)(time*100) );
        //fill_on
        //if(fabs(time - 1.00) < 0.0010)
        if((int)(time*100) == 99)
        {
            printf("""%6.2f: event %s\n", time, "fill_on");
            G1 = 1;
        }
        //fill_off
        //if(fabs(time - 2.00) < 0.001)
        if((int)(time*100) == 199)
        {
            printf("""%6.2f: event %s\n", time, "fill_off");
            G1 = 0;
        }
        //if(fabs(time - 8.00) < 0.001)
        if((int)(time*100) == 800)
        {
            printf("""%6.2f: event %s\n", time, "drain_on");
            G2 = 1;
        }

        Q1 = G1 * (P1 - P2);
        Q2 = G2 * (P3 - P2);

//printf(" Q1 = %d ",Q1);
//printf(" Q2 = %d ",Q2);
    // ΔP/Δt = β/V * ∑ Qi

    float dP1dT = 0;
    float dP2dT = 0;

   
    dP1dT = B/V1 * (-Q1) ;
    dP2dT = B/V2 * (Q1-Q2);
    // Pt + Δt = Pt + Δt *(ΔP/Δt)

    Pnext_P1 = Pcurr_P1 + 0.01 * dP1dT;
    P1 = Pnext_P1;
    Pnext_P2 = Pcurr_P2 + 0.01 * dP2dT;
    P2 = Pnext_P2;

  //  printf("%6.2f: accumulator %.5f cylinder %.5f\n", time, P1, P2);
    time = time + 0.01;
    }

}
