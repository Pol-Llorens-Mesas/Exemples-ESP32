
import json
import argparse

# Configurar els arguments que es passen pel terminal
parser = argparse.ArgumentParser()
parser.add_argument("--fitxer", required=True)
args = parser.parse_args()

# Obrir i llegir el fitxer JSON
with open(args.fitxer, "r", encoding="utf-8") as fitxer:
    dades = json.load(fitxer)

# Inicialitzar els comptadors
total = len(dades)
valids = 0
invalids = 0
critic = 0
avis = 0
estables = 0

# Recórrer tots els servidors del fitxer
for servidor in dades:

    # Comprovar que existeixen els camps necessaris
    if "nom" not in servidor or "cpu_pct" not in servidor or "memoria_pct" not in servidor:
        invalids += 1
        continue

    cpu = servidor["cpu_pct"]
    memoria = servidor["memoria_pct"]

    # Comprovar que CPU i memòria són valors numèrics
    if not isinstance(cpu, (int, float)) or isinstance(cpu, bool) or not isinstance(memoria, (int, float)) or isinstance(memoria, bool):
        invalids += 1
        continue

    # Comprovar que els valors estan entre 0 i 100
    if cpu < 0 or cpu > 100 or memoria < 0 or memoria > 100:
        invalids += 1
        continue

    # Classificar el servidor segons el consum de recursos
    if cpu >= 90 or memoria >= 90:
        critic += 1
    elif cpu >= 70 or memoria >= 70:
        avis += 1
    else:
        estables += 1

    # Comptar el servidor com a vàlid
    valids += 1

# Crear el diccionari amb el resum de l'anàlisi
resum = {
    "serveis_totals_llegits": total,
    "serveis_valids_analitzats": valids,
    "serveis_critics": critic,
    "serveis_avis": avis,
    "serveis_estables": estables,
    "registres_invalids_descartats": invalids
}

# Crear el fitxer JSON amb el resum
with open("informe_salut.json", "w", encoding="utf-8") as fitxer:
    json.dump(resum, fitxer, indent=4, ensure_ascii=False)

# Mostrar els resultats per consola
print("Informe de salut generat correctament a 'informe_salut.json'.")
print("Serveis totals llegits:", total)
print("Serveis vàlids analitzats:", valids)
print("Serveis en estat CRÍTIC:", critic)
print("Serveis en estat AVÍS:", avis)
print("Serveis ESTABLES:", estables)
print("Registres invàlids descartats:", invalids)
