def numeral_to_word_seq(self, num_string):
        """
        Accepts string of numbers only and returns corresponding word sequence
        Parameters: num_string: string
                    A string that contains numeral(s).
        Returns:    read_num: string
                    A sequence of words corresponding with number i.e how
                    number(s) in num_strings would be read in Indonesian.
        """
        # partition into groups of three
        # if '.' in numeral:
        # if numeral.index('.') == 2:
        # numeral = numeral.split('.')[0]
        nlen = len(num_string)
        thous = int((nlen - 1) / 3)
        # check if number is very large or starts with 0 (phone number)
        if thous > 5 or num_string.startswith("0"):
            return " ".join([self.nomor[n] for n in num_string])
        fill = num_string.zfill((thous + 1) * 3) if nlen % 3 != 0 else num_string

        res = []
        for i, num in enumerate([fill[i : i + 3] for i in range(0, len(fill), 3)]):
            n0, n1, n2 = num
            if n0 != "0":
                if n0 == "1":
                    res.append("seratus")
                else:
                    res.extend([self.nomor[n0], "ratus"])
            if n1 != "0":
                if n1 == "1":
                    if n2 == "0":
                        res.append("sepuluh")
                    elif n2 == "1":
                        res.append("sebelas")
                    else:
                        res.extend([self.nomor[n2], "belas"])
                else:
                    res.extend([self.nomor[n1], "puluh"])
            if n2 != "0" and n1 != "1":
                if n2 == "1" and n1 == "0" and n0 == "0" and thous - i == 1:
                    res.append("seribu")
                    continue
                else:
                    res.append(self.nomor[n2])
            if thous - i > 0:
                res.append(self.base[thous - i])
        return " ".join(res)
