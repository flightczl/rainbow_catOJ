import os
from flask import *
app = Flask(__name__)
@app.route("/")
def index():
    return render_template("index.html")
@app.route("/problemlist")
def problemlist():
    return render_template("problemlist.html")
@app.route("/P1000")
def P1000(): 
    return render_template("P1000.html")
@app.route("/about")
def about():
    return render_template("about.html")
@app.route("/submit")
def submit():
    return render_template("submit.html")
@app.route("/submitcode")
def submitcode():
    pid = request.values.get("pid")
    code = request.values.get("code")
    file = open("input.ini", "w")
    file.write(pid)
    file.close()
    file = open(".\\code\\temp.cpp", "w")
    file.write(code)
    file.close()
    os.system("start main.exe")
    return redirect("/result")
@app.route("/result")
def result():
    return render_template("result.html")
#app.run(host="192.168.0.110", port=80, debug=True)
app.run(host="127.0.0.1", port=80) # run server, host=ip
