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
    float time;                  //时间
    char pos_state;              //定位状态
    float latitude;               //纬度
    char a;                    //南北半球
    char b;                    //东经或西经
    float longitude;             //经度
    float speed;                //移动速度
    float direction;              //方向
    UINT date;                  //日期
    float declination;          //磁偏角
    char dd;                    //磁偏角方向
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
        printf("GPS状态位: %c [A:有效定位  V:无效定位]\n", gprmc.pos_state);
        printf("GPS模式位: %c [A:自主定位  D:差分 E:估算 N:数据无效 \n", gprmc.mode);
        printf ("日期:  20%02d-%02d-%02d \n", gprmc.date%100, gprmc.date/100%100, gprmc.date/10000);
        printf ("时间： %02d:%02d:%02d \n",(int)(gprmc.time)/10000 + 8, (int)(gprmc.time)/100%100, (int)(gprmc.time)%100);
        printf ("纬度:  %c:%.3f \n", gprmc.a, gprmc.latitude/100);
        printf ("经度:  %c:%.3f \n", gprmc.b, gprmc.longitude/100);
        printf ("速度:  %.3f \n", gprmc.speed);

	return 0;
}
