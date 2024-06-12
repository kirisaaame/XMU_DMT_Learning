import zipfile

filenames = ["svd.py", "pca.py"]

f = zipfile.ZipFile("answer.zip", "w", zipfile.ZIP_DEFLATED)
for filename in filenames:
    f.write(filename)
f.close()