#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
typedef unsigned int UINT;
 typedef int BYTE;
typedef long int WORD;
typedef struct __gprmc__
{
    float time;                  //ʱ��
    char pos_state;              //��λ״̬
    float latitude;               //γ��
    char a;                    //�ϱ�����
    char b;                    //����������
    float longitude;             //����
    float speed;                //�ƶ��ٶ�
    float direction;              //����
    UINT date;                  //����
    float declination;          //��ƫ��
    char dd;                    //��ƫ�Ƿ���
    char mode;
}GPRMC;

int gps_analysize (char *gps_buff, GPRMC *gprmc)
{
    char *ptr = NULL;

    if(NULL == gprmc)
    {
        printf("parament gprmc error");
        return -1;
    }
    if((strlen(gps_buff)) < 10)
    {

        printf ("gps_buff error\n");
    }

    if(NULL == (ptr = strstr(gps_buff, "$GPRMC")))
    {
        printf ("cannot find \"$GPRMC\".\n");
        return -1;
    }

    sscanf (ptr, "$GPRMC,%f,%c,%f,%c,%f,%c,%f,%f,%d,,,%c", \
            &(gprmc->time),&(gprmc->pos_state),&(gprmc->latitude),&(gprmc->a),&(gprmc->longitude),&(gprmc->b),&(gprmc->speed),&(gprmc->direction),&(gprmc->date),&(gprmc->mode));
    return 0;
} /* ----- End of gps_analysize()  ----- */

int main()
{
	printf("11111\n");
	char gpsdata[] = "$GPRMC,043403.000,A,3029.6468,N,11423.6176,E,0.15,";
    GPRMC gprmc;

        gps_analysize(gpsdata, &gprmc);

        printf("------------ GPS ANALYSIZE DATA --------------\n");
        printf("GPS״̬λ: %c [A:��Ч��λ  V:��Ч��λ]\n", gprmc.pos_state);
        printf("GPSģʽλ: %c [A:������λ  D:��� E:���� N:������Ч \n", gprmc.mode);
        printf ("����:  20%02d-%02d-%02d \n", gprmc.date%100, gprmc.date/100%100, gprmc.date/10000);
        printf ("ʱ�䣺 %02d:%02d:%02d \n",(int)(gprmc.time)/10000 + 8, (int)(gprmc.time)/100%100, (int)(gprmc.time)%100);
        printf ("γ��:  %c:%.3f \n", gprmc.a, gprmc.latitude/100);
        printf ("����:  %c:%.3f \n", gprmc.b, gprmc.longitude/100);
        printf ("�ٶ�:  %.3f \n", gprmc.speed);

	return 0;
}
