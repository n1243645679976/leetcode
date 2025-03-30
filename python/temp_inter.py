import subprocess

process = subprocess.Popen(
    ["python", "temp.py"],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

while True:
    # 從子程式讀取輸出
    process.stdin.write(user_input + '\n')
    output = process.stdout.readline()
    if output == '' and process.poll() is not None:
        break
    if output:
        print(f"Child says: {output.strip()}")
    
    # 給子程式輸入數據
    user_input = input("Enter something to send to the child: ")
    process.stdin.write(user_input + '\n')
    process.stdin.flush()


# 確保子程式終止
process.terminate()
process.wait()