import os

def createFolder(folder):
    if not os.path.exists(folder):
        os.makedirs(folder)


def replace(folderName, filesList):
    for file in filesList:
        os.replace(file, f"{folderName}/{file}")

if __name__ == '__main__':
    
    files = os.listdir()
    files.remove("AutomaticFolderCleaner.py")

    createFolder("Images")
    createFolder("Documents")
    createFolder("Medias")
    createFolder("Others")

    imgExt = [".jpeg", ".jpg", ".png", ".gif",
            ".tiff", ".psd", ".eps", ".ai", ".indd", ".raw"]
    docExt = [".doc", ".docx", ".odt", ".pdf", ".xls",
            ".xlsx", ".ods", ".ppt", ".pptx", ".txt", ".zip", ".exe"]
    mediaExt = [".aif", ".cda", ".mid", ".midi", ".mp3",
                ".mpa", ".ogg", ".wav", ".wma", ".wpl", ".mp4", ".flv"]
    others = []

    images = [file for file in files if os.path.splitext(file)[1].lower() in imgExt]
    documents = [file for file in files if os.path.splitext(file)[1].lower() in docExt]
    medias = [file for file in files if os.path.splitext(file)[1].lower() in mediaExt]

    for file in files:
        extension = os.path.splitext(file)[1].lower()
        if (extension not in imgExt) and (extension not in docExt) and (extension not in mediaExt) and os.path.isfile(file):
            others.append(file)

    replace("Images", images)
    replace("Documents", documents)
    replace("Medias", medias)
    replace("Others", others)