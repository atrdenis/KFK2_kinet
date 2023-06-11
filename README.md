# KFK-2 kinetic (КФК-2 кинетика)
This is a project to determine the kinetics of changes in optical density according to the data from the KFK-2 photocolorimeter
At the input, the program receives voltage data from KFK-2 via the serial port
For KFK2 0 V = 0% transmission, 0.1 V = 100% transmission
The user enters the values for the analysis time and the interval for collecting data from the serial port
The kinetics of changes in optical density over time is determined by linear regression
The collected data is saved in the file "data.txt"
When you press the start button, data collection and calculations begin
Pressing the Stop button disconnects from the serial port and stops collecting data
When the Reset button is pressed, the collected data is written to a file and the variables are cleared.
For questions, write to atrdenis@gmail.com


Это проект по определению кинетики изменения оптической плотности по данным фотоколориметра КФК-2.
На вход программа получает данные напряжения от КФК-2 через последовательный порт.
Для КФК-2 0В = 0 % пропускания, 0,1 В = 100 % пропускания.
Пользователь вводит требуемое время анализа и интервал сбора данных с последовательного порта.
Кинетика изменения оптической плотности во времени определяется методом линейной регрессии
Собранные данные сохраняются в файле "data.txt".
При нажатии на кнопку "Start" начинается сбор данных и расчеты
При нажатии кнопки "Stop" происходит отключение от последовательного порта и прекращение сбора данных.
При нажатии кнопки "Reset" собранные данные записываются в файл, а переменные очищаются.
По вопросам пишите на atrdenis@gmail.com

## Connection to PC:
![ConnectionScheme](https://github.com/atrdenis/KFK2_kinet/blob/main/ConnectionScheme.jpg)

## Arduino Device Scheme:
![ArduinoScheme](https://github.com/atrdenis/KFK2_kinet/blob/main/ArduinoScheme.jpg)
