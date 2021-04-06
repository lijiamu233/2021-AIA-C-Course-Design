#include"./include/header.h"

extern int mousex, mousey, mousepress;
/************************************************************************
FUNCTION:hz_input
DESCRIPTION: �������뷨
INPUT:x1,x2,y1,y2,s,len,color
RETURN:���ָ���len
************************************************************************/
int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color)
{
	int i;
	int ST=-1;//���뷨���ط�ʽ��1.��SPACE���������뺺�� 2.��ENTER����������Ӣ�� 3.�˸�����ز�����
	char *image;
	char *p=s+len;
	int value=0;
	int asc;
	int xx1=x1+2,xx2=x2-2;//��ֹ�������
	int L_maxwords=(xx2-xx1)/8,maxline=(y2-y1)/30;
	int Line=len/L_maxwords+1,L_len=len%L_maxwords,pylen;    //��ǰ��������Line����0�п�ʼ������ ���г��� L_len  pylenƴ������ //�п�30����
	int barx1,barx2,bary1,bary2;
	char str[3]={'\0','\0','\0'};//һ������װ��
	char py[12]={'\0','\0','\0','\0','\0','\0','\0','\0',
	            '\0','\0','\0','\0'};//ƴ���ַ���(�����ַ���)
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	/*while(bioskey(1))//������̻�����  ��ֹ������
	{
		bioskey(0);
	}*/
	if((image=(char* )malloc(8241))==NULL)
	{
		closegraph();
		printf("error!,hz_input");
		getch();
		exit(1);
	}
	while(1)
	{
		mousemove();
		if(value=get_c())
		{
			//clrmous(MouseX,MouseY);
			/*���������*/
		    switch(value)
			{
				case '\b':
					if(L_len==0&&Line>1)//���д���
					{
						L_len=L_maxwords;
						Line--;
					}
					else if(L_len<=0&&Line==1) break;//ɾ������ �޷�ɾ��
					if(*(p-1)>31&&*(p-1)<127)
					{
						setfillstyle(1,color);
						bar(xx1+L_len*8-8,y1+Line*30-28,xx1+L_len*8,y1+Line*30-2);
						p--;
						*p='\0';
						len--;
						L_len--;
					}
					else
					{
						setfillstyle(1,color);
						bar(xx1+L_len*8-16,y1+Line*30-28,xx1+L_len*8,y1+Line*30-2);
						p-=2;
						p[0]='\0';
						p[1]='\0';
						len-=2;
						L_len-=2;
					}
					break;
				case '/n':
					*p='\0';
					free(image);
					return len;	//��������
			}
			/*���뺺�����뷨*/
			asc=value&0xff;
			if(asc>=97&&asc<=122)
			{
				barx1=(x1+L_len*8-50>0)?(x1+L_len*8-50):0;       //�������뷨λ��  �����������Ͻ��Ҳ������Ļ
	    		barx2=(barx1+200<630)?(barx1+200):(barx1=430,630);
				bary1=y1+Line*30+10;
				bary2=(bary1+40<480)?(bary1+40):(bary1=y1+Line*30-80,bary1+40);
				getimage(barx1,bary1,barx2,bary2,image);
				pyFrm(barx1,bary1,barx2,bary2);
				setfillstyle(1,color);
				ST=input_method(barx1,bary1,str,value,py);
				switch(ST)
				{
					case 1://�����ּ���ո���˳����뷨  ���뺺��
					    if(strlen(str))//�����ַ�������Ϊ��
						{
							if(L_len+1>=L_maxwords&&Line<maxline)//��������
							{
								/*�ÿո��������λ����ת����һ��*/
								if(L_len+1==L_maxwords)
								{
									*p=' ';
									p++;
									len++;
								}
								Line++;
								L_len=0;
							}
							else if((L_len+1>=L_maxwords&&Line==maxline)||Line>maxline)//�޷�����
							{
								putimage(barx1,bary1,image,0);
								break;
							}
							strcpy(p,str);
							drawtext(xx1+L_len*8,y1+Line*30-23,str,16,16,16,DARKGRAY);
							p+=2;
					    	len+=2;
							L_len+=2;
						}
						putimage(barx1,bary1,image,0);
					    break;
					case 2://�ɻس����˳����뷨 ���������ģ�
						pylen=strlen(py);
					    if((L_len+pylen>L_maxwords&&Line==maxline)||(Line>maxline))//λ������
						{
							putimage(barx1,bary1,image,0);
							break;
						}
						else if(L_len+pylen>L_maxwords&&Line<maxline)//�������� ����
						{
							for(i=0;i<L_maxwords-L_len;i++)
							{
								p[i]=' ';
							}
							p+=L_maxwords-L_len;
							len+=L_maxwords-L_len;
							Line++;
							L_len=0;
						}
						putimage(barx1,bary1,image,0);
						setcolor(DARKGRAY);
						xouttextxy(xx1+L_len*8,y1+Line*30-21,py,DARKGRAY);
						strcpy(p,py);
						len+=pylen;
						p+=pylen;
						L_len+=pylen;
					    break;
					case 3://����ɾ��Ϊ0�Զ��˳����뷨  ������
						putimage(barx1,bary1,image,0);
					    break;
				}
				value=0;
				ST=-1;
			}
			else if(asc>31&&asc<127)//�ַ�����
			{
				py[0]=asc;
				if(L_len+1<=L_maxwords&&Line<=maxline)//��������
				{
					*p=asc;
				}
				else if(Line+1<=maxline)//��������
				{
					*p=' ';
					Line++;
					L_len=0;
				}
				else
				{
					continue;
				}
				p++;
				len++;
				setcolor(DARKGRAY);
				xouttextxy(xx1+L_len*8,y1+Line*30-21,py,DARKGRAY);
				L_len++;
			}
			memset(py,'\0',12);
			memset(str,'\0',3);
		}
		if((mousex<x1||mousex>x2||mousey<y1||mousey>y2) && mousepress)
		{
			*p='\0';
			free(image);
			return len;
		}
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

/************************************************************************
FUNCTION:input_method
DESCRIPTION: �������뷨����
INPUT:x,y,str,value,py
RETURN:1:������֣�2�������ĸ��3������ո�
************************************************************************/
int input_method(int x,int y,char *str,int value,char *py)
{
	FILE *fp=NULL,*oldfp=NULL;
	int fJudge=FAIL;
	char *p=py;
	int trigger=1;//����ʱ���������־
	char temphz[5][3]={{'\0','\0','\0'},{'\0','\0','\0'},
	                   {'\0','\0','\0'},{'\0','\0','\0'},
					   {'\0','\0','\0'}},temp[3];
	int fposition=0;
	int hznow=0,hznum=0;
	int asc,i;
	int PyStartx=x+8,PyStarty=y+4;
	int HzStartx=x+8,HzStarty=y+22;
	char *ABpath=".//pinyin//";//����ƴ��������׼·��
	char pypath[45]={".//pinyin//"};//����ƴ���������·��
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	while (1)
	{
		mousemove();
		if(value=get_c())//��һ�ν����Զ����� �Ժ�������
		{
			//clrmous(MouseX,MouseY);
			
			//if(kbhit())
			asc=value&0xff;
			/*���ⰴ������*/
			switch(value)
			{
				case '\b':
					p--;
					*p='\0';
					if(py[0]=='\0')
					{
						if(oldfp) fclose(oldfp);
						if(fp) fclose(fp);
						return 3;
					}
					break;
				case ' ':
					strcpy(str,temphz[hznow]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case '\n':
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 2;
				case LASTLINE:
					if(fposition>=8)//�������ض�λ�ļ�ָ��ǰ�˸��ֽڣ��ĸ����֣�
					{
						fposition-=8;
					}
					break;
				case NEXTLINE:
					if(!feof(fp))//�������ض�λ�ļ�ָ���˸��ֽڣ��ĸ����֣�
					{
						fposition+=8;
					}
					break;
				case LEFT://���ƶ�һ��
					if(hznow)
					{
						hznow--;
					}
					else if(fposition>=8)//��Ҫ��ҳ
					{
						fposition-=8;
						hznow=3;
					}
					break;
				case RIGHT:
					if(hznow<hznum-1)//ͬ��
					{
						hznow++;
					}
					else if(!feof(fp))
					{
						fposition+=8;
						hznow=0;
					}
					break;
					/*�����ּ�ѡ�����뺺��*/
				case FIRST:
					strcpy(str,temphz[0]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case SECOND:
					strcpy(str,temphz[1]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case THIRD:
					strcpy(str,temphz[2]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
				case FOURTH:
					strcpy(str,temphz[3]);
					if(oldfp) fclose(oldfp);
					if(fp) fclose(fp);
					return 1;
			}
			/*�����ַ�����*/
			if(asc>31&&asc<127&&strlen(py)<MAXPY&&asc!='['&&asc!=']')    //��Ч����ʱ��λ
			{
				*p=asc;
				p++;
				fposition=0;
				hznow=0;
			}
			pyFrm(x,y,x+200,y+40);
			setfillstyle(1,WHITE);
			settextstyle(1,0,2);
			outtextxy(PyStartx,PyStarty,py);        //ƴ������
		    strcat(pypath,py);
		    strcat(pypath,".txt");
		    if(fJudge) //����ǰ�ļ�ָ�뱣�� ͬʱ�ر���һ���ļ�  Ϊ���������ַ�׼��
			{
				if(oldfp)
				{
					fclose(oldfp);
				}
				oldfp=fp;
			}
		    if((fp=fopen(pypath,"r"))==NULL)//�����ַ�����  ������һ���ļ��������
		    {
		    	fJudge=FAIL;
		    	fp=oldfp;
			}
			else
			{
				fJudge=SUCCESS;
			}
			if(fp)
			{
				fseek(fp,fposition,SEEK_SET);
		  		for(i=0;i<5;i++)
		    	{
		    		fread(temphz[i],2,1,fp);//����һ������
		    		if(feof(fp))//�����ļ�β
		    		{
		    			hznum=i;//������˴��ļ�β���һ�� ��Ҫ��һ  Ȼ���˴�����һ��Ч������
		    			break;
					}
				}
				if(!feof(fp))//δ�����ļ�β ȫ�Ժ���
				{
					hznum=4;
				}
				for(i=0;i<hznum;i++)
				{
					setcolor(BLUE);
                    settextstyle(1,0,2);
		   		    xouttextxy(HzStartx+i*50,HzStarty+5,itostr(i+1,temp),DARKGRAY);
    				drawtext(HzStartx+i*50+16,HzStarty,temphz[i],16, 16,16,DARKGRAY);
				}
				drawtext(HzStartx+hznow*50+16,HzStarty,temphz[hznow],16,16, 16,CYAN);//��ʾѡ�к���
			}
		}
		strcpy(pypath,ABpath);          //����·����ԭ�������٣�
		//value=0;
		drawmouse();
#ifdef _MSC_VER
		delay_ms(50);
#else
		delay(50);
#endif
	}
}

/************************************************************************
FUNCTION:itostr
DESCRIPTION: ���ֱ��
INPUT:a,s
RETURN:����s
************************************************************************/
char *itostr(int a,char *s)
{
	switch(a)
	{
		case 1:
			strcpy(s,"1.");
			return s;
		case 2:
			strcpy(s,"2.");
			return s;
		case 3:
			strcpy(s,"3.");
			return s;
		case 4:
			strcpy(s,"4.");
			return s;
	}
	return s;
}

/************************************************************************
FUNCTION:pyFrm
DESCRIPTION: ���뷨С��
INPUT:x1,y1,x2,y2
RETURN:��
************************************************************************/
void pyFrm(int x1,int y1,int x2,int y2)
{
	setfillstyle(1,WHITE);
	bar(x1,y1,x2,y2);
	setcolor(BLUE);
	setlinestyle(0,0,1);
	line(x1+5,y1+20,x2-5,y1+20);
	setcolor(DARKGRAY);
	rectangle(x1,y1,x2,y2);
}
/************************************************************************
FUNCTION:xouttextxy
DESCRIPTION: �ַ����뷨
INPUT:x,y,s,color
RETURN:�ַ�����len
************************************************************************/
int xouttextxy(int x,int y,char *s,int color)//8x16�����ֿ�
{
	FILE *asc=NULL;
	int i,j,k;
	char *mat,*temp;
	int len;
	long offset;
	int mask;

	len=strlen(s);
	if(!len) return 0;//���ַ�����ִ�в���
	if((asc=fopen(".//HZK//ASC16","rb"))==NULL)
	{
		closegraph();
		printf("outtextxy can't open asc16!,xouttextxy");
		delay(3000);
		exit(1);
	}
	if((mat=(char *)malloc(16*sizeof(char)*len))==NULL)//��ŵ���
	{
		closegraph();
		printf("Failed!,xouttextxy");
		fclose(asc);
		getch();
		exit(1);
	}
	temp=mat;
	for(i=0;i<len;i++)
	{
		offset=(long)16*s[i];//�����ַ����ļ�ƫ��
		fseek(asc,offset,SEEK_SET);
		fread(temp,sizeof(char),16,asc);//�������ַ��������mat
		temp+=16;
	}
	fclose(asc);
	for(i=0;i<len;i++)//ͨ���ŵ���ʾ�ַ�
	{
		for(j=0;j<16;j++)
		{
			mask=0x80;
			for(k=0;k<8;k++)
			{
				if(mat[i*16+j]&mask)
				putpixel(x+8*i+k,y+j,color);
				mask>>=1;
			}
		}
	}
	free(mat);
	return len;
}

/************************************************************************
FUNCTION:hz_int
DESCRIPTION: �����ַ�������ʾ
INPUT:x1,y2,x2,y2,s,color
RETURN:��
************************************************************************/
void hz_int(int x1,int y1,int x2,int y2,char *s,int color)
{
	int len=0;
	int xx1=x1+2,xx2=x2-2;
	int L_maxwords=(xx2-xx1)/8,maxline=(y2-y1)/30;
	int Line=len/L_maxwords+1,L_len=len%L_maxwords;   
	char str[3]={'\0','\0','\0'};
	char py[2]={'\0','\0'};
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	while(*s!='\0')
	{
		if(*s!='\0')
		{
			if(*s>=33&&*s<=122)
			{
				py[0]=*s;
				s++;
			}
			else 
			{
				str[0]=*s;
				s++;
				str[1]=*s;
				s++;
				str[2]='\0';
			}
		}
		if(L_len+1>=L_maxwords&&Line<maxline)
		{
			if(L_len+1==L_maxwords)
			{
				len++;
			}
			Line++;
			L_len=0;
		}
		if(strlen(str))
		{

			if((L_len+1>=L_maxwords&&Line==maxline)||Line>maxline)
			{
				break;
			}
			drawtext(xx1+L_len*8,y1+Line*30-23,str,16,16,16,color);
			len+=2;
			L_len+=2;
			memset(str,'\0',3);
		}
		if(strlen(py))
		{
			if(Line+1<=maxline&&L_len+1>=L_maxwords)
			{
				Line++;
				L_len=0;
			}
			len++;
			setcolor(color);
			xouttextxy(xx1+L_len*8,y1+Line*30-21,py,color);
			L_len++;
			memset(py,'\0',2);
		}
	}
}