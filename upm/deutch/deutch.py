WORD = "WORD"
SAMOST = "SAMOST"
KI = "KI"

class Token:
    def __init__(self, type, slo, de, gender = None):
        self.type = type
        self.slo = slo
        self.de = de
        self.gender = gender
    def __str__(self):
        return f"{self.type}: {self.slo} {self.de}"
    def __repr__(self):
        return f"{self.type}: {self.slo} {self.de}"

# Majhen zelen mozh,     ki barva  grdo      rjavo mizo,     vidi  veliko chrno   kravo.
# klein  gruen Mann (M)     faerbt haesslich braun Tisch (M) sieht gross  schwarz Kuh (Z)

def get_tokens():
    slo = input()
    deu = input()

    tokens = []
    n = int(input())
    sparts = slo.split()
    dparts = deu.split()
    j = 0
    for i in range(len(sparts)):
        spart = sparts[i].strip(",")
        dpart = dparts[j]

        if dpart[0].isupper():
            gender = dparts[j + 1].strip("()") 
            samost = Token(SAMOST, spart, dpart, gender)
            tokens.append(samost)
            j += 2
        elif spart == "ki":
            tokens.append(Token(KI, "ki", "-"))
        else:
            j += 1
            tokens.append(Token(WORD, spart, dpart))
    return tokens


class Parser:
    def __init__(self, tokens):
        self.tokens = tokens 
        self.pos = 0
        self.curr_token = tokens[0]

    def advance(self):
        if self.pos < len(tokens):
            self.pos += 1
        if self.pos == len(tokens):
            self.curr_token = None
        else:
            self.curr_token = self.tokens[self.pos]
    
    def eat(self, ttypes):
        if self.curr_token and self.curr_token.type in ttypes:
            self.advance()
        else:
            raise Exception("error")

    def stavek(self):
        return " ".join([self.osebek(), self.povedek(), self.osebek(False)])

    def osebek(self, je_osebek = True):
        pridevniki = []
        while self.curr_token and self.curr_token.type == WORD:
            pridevniki.append(self.pridevnik())

        sklon = "imenov" if je_osebek else "toz"
        spol = self.curr_token.gender

        samostalnik = self.samostalnik()
        ima_odvisnik = self.curr_token and self.curr_token.type == KI

        map = {
            "dol": {
                "imenov": {
                    "M": { "clen": "der", "suf": "e"},
                    "Z": { "clen": "die", "suf": "e"},
                    "S": { "clen": "das", "suf": "e"},
                },
                "toz": {
                    "M": { "clen": "den", "suf": "en"},
                    "Z": { "clen": "die", "suf": "e"},
                    "S": { "clen": "das", "suf": "e"},
                },
            },
            "nedol": {
                "imenov": {
                    "M": { "clen": "ein", "suf": "er"},
                    "Z": { "clen": "eine", "suf": "e"},
                    "S": { "clen": "ein", "suf": "es"},
                },
                "toz": {
                    "M": { "clen": "einen", "suf": "en"},
                    "Z": { "clen": "eine", "suf": "e"},
                    "S": { "clen": "ein", "suf": "es"},
                },
            },
        }

        dol_nedol = "dol" if ima_odvisnik else "nedol"
        clen = map[dol_nedol][sklon][spol]["clen"]
        pridevnik_suf = map[dol_nedol][sklon][spol]["suf"]

        result = clen + " "
        for prid in pridevniki:
            result += prid + pridevnik_suf +  " "
        result += samostalnik

        if ima_odvisnik:
            self.eat(KI)
            povedek = self.povedek()
            predmet = self.osebek(False)
            result += ", " + self.format_ki(spol) + " " + predmet + " " + povedek + ","
        return str(result)

    def format_ki(self, spol):
        if spol == "M":
            return "welcher"
        elif spol == "Z":
            return "welche"
        return "welches"

    def povedek(self):
        token = self.curr_token
        self.eat(WORD)
        return token.de

    def samostalnik(self):
        token = self.curr_token
        self.eat(SAMOST)
        return token.de

    def pridevnik(self):
        token = self.curr_token
        self.eat(WORD)
        return token.de


tokens = get_tokens()
parser = Parser(tokens)
stavek = parser.stavek().strip(",")
stavek = stavek[0].upper() + stavek[1:] + "."

print(stavek)
