#pragma once

//#include "Lig.h"

#pragma pack(push)
#pragma pack(1)
typedef struct
{
	////*C 类组播组 239.255.0.160 消息编号 11*/////

	unsigned char AlerterReset;							//0x1001 警惕重置 1,  unsigned, 0 = No, 1 = Yes,  N/A
	unsigned char AlerterAlarm;							//0x1002  警惕报警 1,  unsigned,  0 = False,  1 = True,  N/A 
	unsigned char AlerterCutout;						//0x1003 警惕切除 1,  unsigned,  0 = False 1 = True,  N/A 
	unsigned char AutomaticBrakeHandlePos;				//0x1004 自动制动手柄位置 
														//1,  unsigned,   
														//0 = Service Zone, | 制动区 
														//1 = Suppression, | 抑制 
														//2 = Release,| 缓解 
														//3 = Invalid / Other, | 其他 
														//4 = Emergency,  N/A | 紧急

	unsigned char BailOffNCommand;						//0x1005  单独缓解 1,  unsigned,  0 = No Bail,1 = Bail,  N/A 
	unsigned char ConductorValveEmergency;				//0x1007 车长阀紧急 1,  unsigned,  0 = Not Applied, 1 = Applied,  N/A
	float DBCall;										//0x1009  电阻制动百份比 4,  float,  xxx %,  0.01 | 4 字节，浮点数 
	unsigned char DBNotch;								//0x100A 电阻制动档位1,  
														//unsigned,  0 = DB Off, 1 = DB 1, 2 =  DB 2, 
														//3 = DB 3, 4 = DB 4, 5  = DB 5, 
														//6 =	DB 6, 7 = DB 7, 8 = DB 8, 9 = DB Set Up, 10 = Invalid State,  N/A 

	unsigned char EABBrakeSetupMode;					//0x100F 电空制动设置模式 
														//1,  unsigned,  0 = Trail Cut Out | 补机 切除
														//4 = Lead Cut Out | 主机切除 
														//5 = Lead Cut In Vacuum, 
														//6 =	Lead Cut In Freight | 主机切入货车,
														//7 = Lead Cut In Passenger | 主机切入客车,  
														//8 = Other	(Trail Cut In  	Passenger, Trail Cut In Freight), N/A |	其他

	unsigned char EABIBS;								//0x1010 电空制动独立制动施加 1,  unsigned,  0 = False, less than or equal to 80%, 
																	//1 = True, greater than 80%,  N/A 
	unsigned char EABIndBrakeTrail;						//0x1011  从车独立制动施加 1,  unsigned,  0 = Trail, 1 = Lead,  N/A
	unsigned char EABPenaltyType;						//0x1012  电空制动惩罚制动类型 
														//1,  unsigned,  0 = No Penalty, 
														//1 = Alerter Penalty | 警惕惩罚, 
														//2 = Overspeed Penalty | 超速惩罚, 
														//4 = Cab Signal #1 Penalty | 机车信号 1惩罚, 
														//8 = Cab Signal #2 Penalty | 机车信号 2惩罚, 
														//9=Other (Air Brake Failure, PowerUp Penalty, Diagnostic Penalty) | 其他,N/A 

	unsigned char EABSetup;								//0x1013 电空制动设置 
														//1,  unsigned,  0 = Passenger | 客车, 
														//1 = Freight | 货车, 2 = Cut Out | 切除, 
														//3 = Other, N/A | 其他

	unsigned char LCSLeadOrTrail;						//0x1014 本务/重联 电空制动模式设置1,  unsigned,  0 = Lead | 主机, 1 = Trail | 补机,  N/A 
	unsigned char ECSwitch;								//0x1015 引擎控制开关 
														//1,  unsigned,  0 = Jog | 移车, 
														//1 = Start | 发动, 
														//2 = Isolate | 隔离, 
														//3 = Run | 运行, 
														//4 = DB Only | 电阻制动,  N/A

	unsigned char EmergencyBrakesApplied;				//0x1017  紧急制动施加 1,  unsigned,  0 = No, 1 = Yes,  N/A 
	unsigned char HeadlightFront;						//0x1019  前大灯开关 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned char HeadlightRear;						//0x101A 后大灯开关 1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char Horn;									//0x101B  喇叭压力开关 1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char LocomotiveOperatingMode;				//0x101C 机车工作模式
														//1,  unsigned,   
														//	0 = Reset | 重置 , 
														//	1 = Ready NP, 
														//	2 = Crank, 
														//	3 = Crank Clean Up, 
														//	4 = Jog Set Up, 
														//	5 = Jog, 
														//	6 = Jog Clean Up, 
														//	7 = Ready P Set, 
														//	8 = Ready P, 
														//	9 = Ready P Clean, 
														//	10 = Motor Set Up, 
														//	11 = Motor, 
														//	12 = Motor Clean, 
														//	13 = Brake Set Up Config, 
														//	14 = Brake Set Up, 
														//	15 = Brake Set Up Clean Up, 
														//	16 = Brake Config, 
														//	17 = Brake, 
														//	18 = Brake Clean Up, 
														//	19 = Self Test Set Up, 
														//	20 = Self Test, 
														//	21 = Pre Lube Self Test, 
														//	22 = Pre Lube Self Test Clean Up, 
														//	23 = Self Test Clean Up, 
														//	24 = Self Load Set Up, 
														//	25 = Self Load, 
														//	26 = Self Load Clean Up, 
														//	27 = MMM error,28 = MMM done, 
														//	32 = Other, N/A 

	float LocomotiveSpeed;								//0x101D 机车速度4,  float,  xxx.x MPH,  0.1 MPH | 4 字节，浮点数
	float MeasuredFuelLevel;							//0x101F 燃油液位 4,  float,  xxxxx Gallons,  Varies By Fuel Monitor Type Note: Fuel values greater than 6,249 gallons considered invalid 
	unsigned char PCSRelayStatus;						//0x1021  动力切除继电器状态1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char ReverseDirection;						//0x1023  反相开关1,  unsigned,  0 = Forward | 前进,  1 =Centered | 零位,2 = Reverse | 后退, 3 = Undefined,	N/A
	unsigned char SandingMode;							//0x1024  撒沙模式 
														//1,  unsigned,   
														//	0 = Sand Off | 撒沙结束 
														//	1 = Manual Lead Sand |手动主机撒沙 
														//	2 = Manual TL Sand |手动列车线撒沙 
														//	3 = Automatic Sand |自动撒沙, 
														//	4 = EAB Sand | 电空制动撒沙, 
														//	5 = Sand Self Test | 自测试撒沙, N/A

	unsigned char TL27SlowSpeed;						//0x1025 列车管线 27 慢速 1,  unsigned,	0 = De energized,1 = Energized, N/A 
	unsigned char ThrottleNotch;						//0x1027 机车档位
														//1,  unsigned,   
														//	0 = Idle, Brake Set-Up, or Brake | 堕
														//	转，制动设置，或制动,  
														//	1 = Notch 1 | 1 档, 
														//	2 = Notch 2 | 2 档, 
														//	3 = Notch 3 | 3 档, 
														//	4 = Notch 4 | 4 档, 
														//	5 = Notch 5 | 5 档, 
														//	6 = Notch 6 | 6 档, 
														//	7 = Notch 7 | 7 档, 
														//	8 = Notch 8 | 8 档, 
														//	9 = Shutdown | 关闭 
														//	10 Invalid, N/A 

	unsigned char TrainlineEmergency;					//0x1028 |列车管线紧急制动 1,  unsigned,  0 = Not Applied,  1 = Applied, N/A
	unsigned char AlarmSilence;							//0x1029 报警静音 1,  unsigned,  0 = False, 1 = True, N/A
	unsigned char AlerterAudioAlarm;					//0x102A   警惕声音报警 1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char AuxiliaryAlternatorFieldCutout;		//0x102B 辅助发电机励磁切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char ComputerShutdownSwitch;				//0x102C  电脑关闭开关 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned int TotalEngineUsageStat;					//0x102F 引擎应用状态，4,  unsigned,  xxxxxxxx Hours,  1 HR |	4 字节无符号数，小时
	unsigned char DynamicBrakeCutout;					//0x1031  电阻制动切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char ECSwitchDBOnly;						//0x1032  引擎控制开关（仅电阻制动）1,  unsigned,  0 = Off,  1 = True, N/A 
	unsigned char ECSwitchJog;							//0x1033 引擎控制开关（移车）1,  unsigned,  0 = Off 1 = On,  N/A
	unsigned char ECSwitchRun;							//0x1034  引擎控制开关（运行）1,  unsigned,  0 = Off 	1 = On,  N/A
	unsigned char ECSwitchStart;						//0x1035 引擎控制开关（发动）1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char EngineStartSwitch;					//0x1036 引擎启动开关 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned char EngineStopButton;						//0x1037 引擎停止按钮 1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char FanReverser;							//0x1038  风扇反转 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char FuelTankBreakerStatus;				//0x1039  油箱断路器状态 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned int GPSSystemTimeDate;						//0x1049 | GPS 系统时间 日期 4,  unsigned,  MM:DD:YY,  1 Day 
	unsigned int GPSCoordinatedUTCTime;					//0x104A GPS UTC 时间 4,  unsigned,  HH:MM:SS,  1 Second 
	unsigned short GPSDateYear;							//0x104B  GPS 日期 年 2,  unsigned,  YYYY,  1 Year
	unsigned char GPSDateMonth;							//0x104C GPS 日期 月 1,  unsigned,  MM,  1 Month 
	unsigned char GPSTimeDay;							//0x104D GPS 日期 日 1,  unsigned,  DD,  1 Day 
	unsigned char GPSTimeHours;							//0x104E GPS 时间 小时 1,  unsigned,  HH,  1 Hour
	unsigned char GPSTimeMinutes;						//0x104F GPS 时间 分钟 1,  unsigned,  MM,  1 Minute 
	unsigned char GPSTimeSeconds;						//0x1050 GPS 时间 秒 1,  unsigned,  SS,  1 Second 
	unsigned char GPSReceiverStatus;					//0x1051  GPS 接受机状态 
														//1,  unsigned,   
														//	0 = Motorola 6 Channel, 
														//	1 = Sony, 
														//	3 = Generic NMEA Device, 
														//	4 = u-blox, 
														//	11 = Motorola 12 Channel,  N/A 

	unsigned char HornMagValve;							//0x1054  喇叭电磁阀 1,  unsigned,0 = Deenergized,1 = Energized, N/A 
	unsigned char HornPushbutton;						//0x1055 喇叭按钮 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned char JogPushbutton;	//移车按钮			//0x1056  移车按钮 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned char LeadAxleSandSwitch;					//0x1059 导向轴撒砂开关 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char LocalControlCircuitBreaker;			//0x105A   本地控制电路断路器 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned char LocalMUShutdown;						//0x105B 本地重联关闭 1,  unsigned,  0 = Off,  1 = On, N/A
	unsigned char LockedAxleCutout;						//0x105C  锁轴切除 1,  unsigned,  0 = False,  1 = On, N/A 
	unsigned char ManualLeadSand;						//0x105D 手动撒沙 1,  unsigned,  0 = False,  1 = True, N/A
	float AmbientAirTemperature;						//0x105E 环境温度 4,  float,  -xxx.x Degree F,  0.1 Degree| 4 字节浮点数 
	unsigned char PowerReductionOn;						//0x1060 降功指示 1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned int RoadNumber;							//0x1061 | 车号 4,  unsigned,  xxxxxxxx ,  N/A 
	unsigned char SelfLoadSwitch;						//0x1062 自负载开关 1,  unsigned,  0 = Off,  1 = On, N/A 
	unsigned char SelfTestRequest;						//0x1063  自负载请求 1,  unsigned,  0 = False,  1 = True, N/A 
	float EngineWaterTemperature;						//0x106D 引擎水温 4, float, -xxx.xx Degrees F, .01 Degrees  | 4 字节浮点数

	////*C 类组播组 239.255.0.160 消息编号 12*/////


	unsigned char AirBrakeFailure;						//0x2001 电空制动失效 1,  unsigned,  0 = No Air Brake Failure, 1	= Air Brake Failure , N/A 
	unsigned int IncidentLog;							//0x2002 故障记录日志 4, unsigned, N/A, N/A 
	unsigned char NumberOfClassC;						//0x2005 发布的 C 类报文数 1, unsigned, N/A, N/A 
	unsigned char NumberOfClassDClientsActive;			//0x2006 D类报文的有效客户端数量 1, unsigned, N/A, N/A 
	unsigned short LIGReconfigurationTimerStatus;		//0x2007  LIG 重配置时钟状态 2, unsigned, xxxxx Seconds, 1 Second 
	unsigned char NumberofDefinedClassCMessages;		//0x2008 定义的 C 类报文数 1, unsigned, N/A, N/A 
	unsigned char NumberofDefinedClassCGroups;			//0x2009 |定义的 C 类报文组数 1, unsigned, N/A, N/A 
	unsigned char NumberofPublishedClassCGroups;		//0x2010 发布的 C 类报文组数目 1, unsigned, N/A, N/A
	float DBBrakePowerControl;							//0x3001  电阻制动功率控制 4,  float,  xx.x Volts,  0.1 Volt | 4 字节浮点数
	unsigned char DBBrakeSetup;							//0x3002 电阻制动设置 1,  unsigned,  0 = False, 1 = True, N/A 
	unsigned char DBBrakeStart;							//0x3003  电阻制动启动 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char TL5EmergencySand;						//0x3004 列车管线 5 紧急撒沙 1,  unsigned,  0 = False, 1 = True, N/A
	unsigned char TL16EngineRun;						//0x3005 列车管线 16 引擎运转 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char TL6GeneratorField;					//0x3006  列车管线 6 现场发电机输入 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char TL20InputBrakeWarning;				//0x3007 列车管线 20 制动警告 1,  unsigned,  0 = Not Active, 1 = Active,N/A 
	unsigned char TrainlineSand;						//0x3008  列车管线 23 列车管线撒沙 1,  unsigned,  0 = False, 1 = True, N/A
	unsigned char WheelSlip;							//0x3009  列车管线 10 车轮滑动 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char TL10CommandedWheelSlip;				//0x300A 列车管线 10 授命的车轮滑动 1,  unsigned,  0 = Not Active, 1 = Active,	N/A 
	unsigned char TL12InputThrottleBV;					//0x300B 车管线 12 档位 B 状态 1,  unsigned,  0 = Not Active, 1 = Active, N/A 
	float TL13Input;									//0x300C 列车管线 13 正向控制输入 4,  float,  xxx.x Volts,  0.1 Volt
	unsigned char TL15InputThrottleAV;					//0x300D 车管线 15 档位 A 状态 1,  unsigned,  0 = Not Active, 1 = Active,	N/A
	unsigned char TL1InputSlowSpeedEnable;				//0x300F 列车管线 1慢速使能输入 1,  unsigned,  0 = Not Active, 1 = Active, N/A 
	unsigned char TL18InputTractiveEffortA;				//0x3010  列车管线 18 牵引功效 A 输入 1,  unsigned,  0 = Not Active, 1 = Active,	N/A 
	unsigned char TL19InputTractiveEffortB;				//0x3011 列车线 19 牵引功效 B 输入 1,  unsigned,  0 = Not Active, 1 = Active, N/A
	unsigned char TL2InputAudioAlarm;					//0x3012 列车线 2响铃警报输入 1,  unsigned,  0 = Not Active, 1 = Active,N/A
	unsigned char TL22InputAirCompressorSync;			//0x3013 列车线 22 空气压缩机同步输入 1,  unsigned,  0 = Not Active,1 = Active, N/A
	float TL24InputNormalized;							//0x3014  列车线 24 正常输入 4,  float,  xx.x Volts ,  0.1 Volt | 4 字节
	unsigned char TL27InputBrakeWarning;				//0x3015  列车管线 27 制动警告 1,  unsigned,  0 = Not Active, 1 = Active
	unsigned char TL3InputThrottleDV;					//0x3016 列车管线 3 档位 D 状态 1,  unsigned,  0 = Not Active, 1 = Active
	unsigned char TL7InputThrottleCV;					//0x3017 列车管线 7 档位 C 状态 1,  unsigned,  0 = Not Active, 1 = Active
	unsigned char TL8DirectionReverseInput;				//0x3018  列车管线 8 后退方向 TL8 1,  unsigned,  0 = Not Active, 1 = Active
	unsigned char TL9DirectionForwardInput;				//0x3019 列车管线 9 前进方向 TL9 1,  unsigned,  0 = Not Active, 1 = Active
	float EngineGrossHorsepower;						//0x4003 引擎马力 4,  float,  xxxx Horsepower,  1 HP
	float EngineRPM;									//0x4004  引擎转速 4,  float,  xxxx.x Revolutions Per Minute,0.1 RPM
	float BatteryVoltage;								//0x5001 电池电压 4,  float,  -xxx.xx Volts ,  0.01 Volt | 4 字节浮点数
	float AuxiliaryHP;									//0x5002  辅助功率 4,  float,  xxxxx Horsepower,  1 HP | 4 字节浮点数
	float AirFlow;										//0x6001   制动管风速 4,  float,  xxx.x CFM,  0.1 CFM | 4 字节浮点数 
	float BrakeCylinderPressure;						//0x6002 制动缸压力 4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数 
	float BrakePipePressure;							//0x6004 制动管压力 4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数 
	float CommandedCylinderPressure;					//0x6005  单独制动阀控制的缸压力 4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数 
	float EqualizingReservoirPressure;					//0x6006 均衡风缸压力 4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数
	float FeedValvePressureSetting;						//0x6007 |制动进给阀压力设定 4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数
	float MainReservoirPressure;						//0x6008 主风缸压力	4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数
	float TargetEqualizingReservoirPressure;			//0x6009  目标均衡风缸压力 4,  float,  xxx.x PSI,  0.1 PSI | 4 字节浮点数 
	float MainAlternatorVolts;							//0x7001  主发电机电压 4,  float,  xxxx.xx Volts,  0.01 Volt | 4 字节浮点数
	unsigned char TM1Cutout;							//0x7002  牵引电机 1 切除 1,  unsigned,  0 = False, 1 = True, N/A 
	unsigned char TM2Cutout;							//0x7003 牵引电机 2 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char TM3Cutout;							//0x7004 牵引电机 3 切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char TM4Cutout;							//0x7005 牵引电机 4 切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char TM5Cutout;							//0x7006 牵引电机 5 切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char TM6Cutout;							//0x7007 牵引电机 6 切除 1,  unsigned,  0 = False,  1 = True, N/A
	float TractionAlternatorCurrentAC;					//0x7008 牵引发电机电流 4,  float,  xxxx.xx Amps,  0.01 Amp | 4 字节浮点数
	float TractionMotor2Current;						//0x700A  牵引电机#2 电流 4,  float,  xxxx.xx Amps,  0.01 Amp | 4 字节浮点数
	float TractionMotor5Current;						//0x700B  牵引电机#5 电流 4,  float,  xxxx.xx Amps,  0.01 Amp | 4 字节浮点数
	float TractiveEffortFeedback;						//0x700C  牵引功效反馈 4,  float,  -xxxxxx Pounds,  1 Pound | 4 字节浮点数 
	unsigned char InverterRequest1;						//0x7013 牵引电机逆变器 1 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char InverterRequest2;						//0x7014 牵引电机逆变器 2 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char InverterRequest3;						//0x7015 牵引电机逆变器 3 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char InverterRequest4;						//0x7016 牵引电机逆变器 4 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char InverterRequest5;						//0x7017 牵引电机逆变器 5 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char InverterRequest6;						//0x7018 牵引电机逆变器 6 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char SpeedSensorCutout1;					//0x7019 速度传感器 1 切除 1,  unsigned,  0 = False,  1 = True, N/A 
	unsigned char SpeedSensorCutout2;					//0x701A 速度传感器 2 切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char SpeedSensorCutout3;					//0x701B 速度传感器 3 切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char SpeedSensorCutout4;					//0x701C 速度传感器 4 切除 1,  unsigned,  0 = False,  1 = True, N/A

	////*C 类组播组 239.255.0.161 消息编号 13*/////

	unsigned char SpeedSensorCutout5;					//0x701D 速度传感器 5 切除 1,  unsigned,  0 = False,  1 = True, N/A
	unsigned char SpeedSensorCutout6;					//0x701E 速度传感器 6 切除 1,  unsigned,  0 = False,  1 = True, N/A
	float TractionHP;									//0x7027 牵引功率 4, float, xxxx.xx HP, 1 HP
	unsigned char CMConsistLeadNotch;					//0xC001  一致性管理器主控档位 
														//1,  unsigned,   
														//	0 = Idle | 堕转, 
														//	1 = N1 | 1 档, 
														//	2 = N2 | 2 档, 
														//	3 = N3 | 3 档, 
														//	4 = N4 | 4 档, 
														//	5 = N5 | 5 档, 
														//	6 = N6 | 6 档, 
														//	7 = N7 | 7 档, 
														//	8 = N8 | 8 档, 
														//	9 = Shutdown | 停机, N/A

	unsigned char CMRelayState;							//0xC002 一致性管理器继电器状态 1,  unsigned,  0 = Picked Up, 1 = Dropped Out, N/A 
	unsigned char CMState;								//0xC003  一致性管理器状态 1,  unsigned,  0 = Reset,  1 =	Disable, 2 = Init, 3 = Enable, 4 = Run, N/A
	unsigned char CMTrailNotch;							//0xC004   一致性管理器从控档位 
														//1,  unsigned,   
														//	0 = Idle | 堕转, 
														//	1 = N1 | 1 档, 
														//	2 = N2 | 2 档, 
														//	3 = N3 | 3 档, 
														//	4 = N4 | 4 档, 
														//	5 = N5 | 5 档, 
														//	6 = N6 | 6 档, 
														//	7 = N7 | 7 档, 
														//	8 = N8 | 8 档, 
														//	9 = Shutdown | 停机, N/A

	unsigned char EngineerInitiatedEmergency;			//0x1018 司机按紧急 1,  unsigned,  0 = No, 1 = Yes,N/A
	float CumMegawattsTractionOnly;						//0x7012 牵引能量 4,  float,  xxxxxxxx Megawatt-Hours,  1MWH
	float GPSLongitude;									//0x1045 GPS 经度 4,  Float,  -xxxx Degrees,  1	Degree
	float GPSLatitude;									//0x1040 GPS 纬度 4,  float,  -xxxx Degrees,  1 Degree

	float DistanceStat;	//2.0 更改						//0x705D 机车运行里程 4, Float, xxxxxxxx Miles, 1 Mile

	float CompADischargeTemperature;					//0x6020 空压机 A 出口温度 4, Float, xxx.x Degrees F, 0.1Degrees
	float CompBDischargeTemperature;					//0x6021 空压机 B 出口温度 4, Float, xxx.x Degrees F, 0.1Degrees
	float CompADischargePressure;						//0x6022  空压机 A 出口压力 4, Float, xxx.x PSI,  0.1 PSI | 4 字节浮点数
	float CompBDischargePressure;						//0x6023  空压机 B 出口压力 4, Float, xxx.x PSI,  0.1 PSI | 4 字节浮点数
	float CompSpeedBitPack;								//0x6024 空压机速度 4, Float, xxxxxx, N/A | 4 字节浮点数

	float MainReservoirPressure1;//2.0 更改				//0x6210  MR1 压力 4, Float, xxx.x PSI, 0.1 PSI

	unsigned char PenaltyBrakeCommand;					//0x7079  LPC 发出惩罚制动指令 1, unsigned Integer, 0 = Apply, 1	=  	Released, N/A
	float LinkAvgVolts;									//0x5021  母线平均电压 4, Float, xxxx.x Volts, 0.1 Volt | 4 字节浮点数
	float DCLPSVoltage5V;								//0x5022 +5 伏电压 4, Float, xx.x Volts, 0.1 Volt 
	float DCLPSVoltage15VP;								//0x5023  +15 伏电压 4, Float, xx.x Volts, 0.1 Volt 
	float DCLPSVoltage15V;								//0x5024  -15 伏电压 4, Float, xx.x Volts, 0.1 Volt

	float TurboSpeedR;//2.0 更改						//0x402C R侧増压器转速 4, Float, -xxxxx RPM, 1 RPM
	float TurboSpeedL;//2.0 更改						//0x402B 左侧増压器转速 4, Float, -xxxxx RPM, 1 RPM
	float OilInletTemp;//2.0 更改						//0x4021 滑油入口温度 4, Float, xxxx.x Degree F, 0.1 Degree

	float WaterOutletTemp;								//0x4022 柴油机出口水温4, Float, -xxx.x Degree F, 0.1 Degree 
	float MainAirTemp;									//0x4023 进气总管温度 4, Float, xxx.x Degree F, 0.1 Degree 
	float PreturbineTempL;								//0x4024  左增压器前温度 4, Float, xxxx Degree F, 1 Degree
	float PreturbineTempR;								//0x4025  右增压器前温度 4, Float, xxxx Degree F, 1 Degree
	float MainAirPressure;								//0x4026 进气总管压力  4, Float, xxx.x PSI, 0.1 PSI 
	float FuelPressure;									//0x4027 燃油压力 4, Float, xxx.x PSI, 0.1 PSI

	float CrankcasePressure;//2.0 更改					//0x4028 柴油机曲轴箱压力 4, Float, xxxx.xx PSI, 0.01 PSI
	unsigned short FilteredLubeOilPressure;	//2.0 更改	//0x402E | 滑油出口压力 2,  unsigned,xxx PSI 

	float OilInletPressure;								//0x4029 柴油机机油进口压力 4, Float, xxx.x PSI, 0.1 PSI 
	float WaterInletPressure;							//0x402A 柴油机冷却水进口压力 4, Float, xxx.x PSI, 0.1 PSI
	float BarometricPressure;							//0x1200 大气压力 4, Float, xx.x PSI, 0.1 PSI
	float TACFieldCurrent;								//0x705E TAC 励磁电流 4, Float, -xxx.x AMPS, 0.1 AMP 
	float TM1TracEffFdbk;								//0x705F  第 1 轴牵引力 4, Float, -xxxxx LB, 1 LB
	float TM2TracEffFdbk;								//0x7060  第 2 轴牵引力 4, Float, -xxxxx LB, 1 LB
	float TM3TracEffFdbk;								//0x7061  第 3 轴牵引力 4, Float, -xxxxx LB, 1 LB
	float TM4TracEffFdbk;								//0x7062  第 4 轴牵引力 4, Float, -xxxxx LB, 1 LB
	float TM5TracEffFdbk;								//0x7063  第 5 轴牵引力 4, Float, -xxxxx LB, 1 LB
	float TM6TracEffFdbk;								//0x7064  第 6 轴牵引力 4, Float, -xxxxx LB, 1 LB
	float AuxAltSrcVoltage;								//0x5025 辅发源电压 4, Float, xxx.x Volts, 0.1 Volt
	float AuxAltVRMS;									//0x5026 辅发电压有效值 4, Float, -xxx Volts, 1 Volt
	float AuxAltFieldCurrent;							//0x5027  辅发励磁电流 4, Float, xxx.x AMPS, 0.1 AMP 

	float AuxAltPhAArms;//2.0 更改						//0x5028  辅发 A 相电流有效值 4, Float, -xxxx.x A RMS, 0.1 ARMS 
	float AuxAltPhBArms;//2.0 更改						//0x5029  辅发 B 相电流有效值 4, Float, -xxxx.x A RMS, 0.1 ARMS
	float AuxAltPhCArms;//2.0 更改						//0x502A  辅发 C 相电流有效值 4, Float, -xxxx.x A RMS, 0.1 ARMS

	float BatteryChargeCurrent;							//0x502B 蓄电池充电电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float TBCPhaseACurrent;								//0x7065 TBC A 相电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float TBCPhaseBCurrent;								//0x7066 TBC B 相电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float TBCPhaseCCurrent;								//0x7067 TBC C 相电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float TAPCurrentAMPSAvg;							//0x7068 TAP 电流  4, Float, xxxx.x AMPS, 0.1 AMP
	float MaxMotorTemp;									//0x7069 最高电机温度 4, Float, xxxx Degree F, 1 Degree
	float Radfan1Status;								//0x706A  #1散热器风扇低速运行 4, Float, xxxxxx, N/A
	float Radfan1PhACurrent;							//0x706B #1 | 风扇 1 A 相电流 4, Float, xxxx.x AMPS, 0.1 AMP 
	float Radfan1PhBCurrent;							//0x706C #1 | 风扇 1 B 相电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float Radfan1PhCCurrent;							//0x706D #1 | 风扇 1 C 相电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float Radfan2Status;								//0x706E  #2散热器风扇低速运行 4, Float, xxxxxx, N/A
	float Radfan2PhACurrent;							//0x706F #2 | 风扇 2 A 相电流 4, Float, xxxx.x AMPS, 0.1 AMP 
	float Radfan2PhBCurrent;							//0x7070 #2 | 风扇 2 B 相电流 4, Float, xxxx.x AMPS, 0.1 AMP
	float Radfan2PhCCurrent;							//0x7071 #2 | 风扇 2 C 相电流 4, Float, xxxx.x AMPS, 0.1 AMP

	float SlipSlides;//2.0 更改							//0x7072  打滑(BP) 4, Float, xxxxxxxx, N/A

	float A1SpeedRaw;									//0x7073 1轴速度 4, Float, -xx.x MPH, 0.1 MPH 
	float A2SpeedRaw;									//0x7074 2轴速度 4, Float, -xx.x MPH, 0.1 MPH 
	float A3SpeedRaw;									//0x7075 3轴速度 4, Float, -xx.x MPH, 0.1 MPH 
	float A4SpeedRaw;									//0x7076 4轴速度 4, Float, -xx.x MPH, 0.1 MPH 
	float A5SpeedRaw;									//0x7077 5轴速度 4, Float, -xx.x MPH, 0.1 MPH 
	float A6SpeedRaw;									//0x7078 6轴速度 4, Float, -xx.x MPH, 0.1 MPH 
	float AvailableHorsepower;							//0x402D 可用功率 4, Float, xxxx HP, 1 HP 
	
	
	////*C 类组播组 239.255.0.161 消息编号 14*/////
	//2.0更改
	//共202项，大小484，1字节对齐

}LIG_INFO_2_0;


typedef struct _ldpToRailway{



	_ldpToRailway()
	{

	};

}ldpToRailway;//LDP发给铁路局的 LIG报文


#pragma pack(pop)


//void LIG_change(LIG_INFO_2_0 *info2, LIG_INFO *info);

////生成发送报文，返回报文长度
//int ToCMDGram(unsigned char* buf /*LDP发给铁路局的 LIG报文*/, LIG_INFO_2_0* info, CLDPDlg* aPram);
