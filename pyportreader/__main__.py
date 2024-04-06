import serial


class Reader:
    def __init__(self, port, baud_rate):
        self.serial = serial.Serial(port, baud_rate)
        self.line = ''
        self.last_line = ''

        self.byte = None
        self.decimal = None
        self.ascii_char = None

    def read_byte(self):
        self.byte = self.serial.read()
        self.decimal = int.from_bytes(self.byte, 'big')
        self.ascii_char = chr(self.decimal)
        print(f'{self.ascii_char}:{self.decimal}:{self.byte}')

    def read_line(self):
        if self.ascii_char != '0':
            self.line += self.ascii_char
        else:
            self.last_line = str(self.line)
            self.line = ''
            print(self.last_line)



port = '/dev/ttyACM0'
baud_rate = 9600

reader = Reader(port, baud_rate)

while True:
    reader.read_byte()
    reader.read_line()

ser.close()