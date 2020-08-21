import os

def detectBinod(filename):
    with open(filename, "r") as f:
        lines = f.read()

    if "binod" in lines.lower():
        return True

    else:
        return False

if __name__ == '__main__':

    contents_list = os.listdir()
    count = 0

    for content in contents_list:
        if content.endswith("txt"):
            print(f"Detecting Binod In {content}")

            flag = detectBinod(content)

            if flag:
                print(f"Binod Found in {content}")
                count += 1

            else:
                print(f"Binod Not Found in {content}")

    print(f"\n{count} Files Have Binod Hidden in Them")
