import wave
from pyaudio import PyAudio,paInt16

from constant import *
def save_wave_file(filename,data):
    with wave.open(filename,'wb') as wf:
        wf.setnchannels(channels)
        wf.setsampwidth(sampwidth)
        wf.setframerate(framerate)
        wf.writeframes(b"".join(data))

def my_record(filename):
    pa=PyAudio()
    stream=pa.open(format = paInt16,channels=1,
                   rate=framerate,input=True,
                   frames_per_buffer=NUM_SAMPLES)
    my_buf=[]
    count=0
    print("录音中")
    while count<TIME*8:#控制录音时间
        string_audio_data = stream.read(NUM_SAMPLES)
        my_buf.append(string_audio_data)
        count+=1
        print('.',end="")
    save_wave_file(filename+".wav",my_buf)
    stream.close()
    print("录制完成")

my_record("test")