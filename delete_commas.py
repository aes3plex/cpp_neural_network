with open("raw_dataset.txt") as infile, open("dataset.txt", "w") as outfile:
    for line in infile:
        outfile.write(line.replace(",", ""))