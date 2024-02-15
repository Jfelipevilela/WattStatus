const express = require('express');
const session = require('express-session');
const bodyParser = require('body-parser');
const mysql = require('mysql2');
const cors = require('cors')




const app = express();
const port = 3100;

// Configuração do banco de dados
const conexao = mysql.createConnection({
    host: 'localhost',
    port: "3306",
    user: 'root',
    password: '',
    database: 'watt'
});

const tariffData  = {
  'ac': 0.828,
  'al': 0.866,
  'ap': 0.722,
  'am': 0.835,
  'ba': 0.808,
  'ce': 0.744,
  'es': 0.696,
  'go': 0.711,
  'ma': 0.719,
  'mt': 0.883,
  'ms': 0.880,
  'mg': 0.751,
  'pa': 0.602,
  'pb': 0.602,
  'pr': 0.639,
  'pe': 0.764,
  'pi': 0.854,
  'rj': 0.840,
  'rn': 0.689,
  'rs': 0.691,
  'ro': 0.709,
  'rr': 0.735,
  'sc': 0.593,
  'sp': 0.680,
  'se': 0.651,
  'to': 0.756,
  'df': 0.766,
} 


// Verifica a conexão com o banco de dados
conexao.connect((err) => {
  if (err) {
    console.error('Erro ao conectar ao banco de dados:', err);
  } else {
    console.log('Conectado ao banco de dados');
  }
});

// Configuração do Express
app.use(session({ secret: 'seu_segredo', resave: true, saveUninitialized: true }));
app.use(bodyParser.urlencoded({ extended: true }));
app.engine('html', require('ejs').renderFile);
app.set('view engine', 'html');
app.set('views', __dirname + '/views');
app.use('/public', express.static(__dirname + '/public'));
app.use(express.json());
app.use(cors())


// Rota de login
app.get('/', (req, res) => {
  res.render('login');
});

app.post('/', (req, res) => {
  const { email, password } = req.body;

  // Verifica se o usuário existe no banco de dados
  const query = 'SELECT * FROM login WHERE email = ? AND senha = ?';
  conexao.query(query, [email, password], (err, results) => {
    if (err) {
      console.error('Erro ao consultar o banco de dados:', err);
      res.status(500).send('Erro interno do servidor');
    } else {
      if (results.length > 0) {
        req.session.email = email;
        res.redirect('/inicio');
      } else {
        res.render('login', { error: 'Credenciais inválidas' });
      }
    }
  });
});

// Rota de cadastro
app.get('/cadastrar', (req, res) => {
  res.render('cadastrar');
});

app.post('/cadastrar', (req, res) => {
    const { name, email, password  } = req.body;
    
    // Verifica se o email já está em uso
    const checkEmailQuery = 'SELECT * FROM login WHERE email = ?';
    conexao.query(checkEmailQuery, [email], (err, emailResults) => {
      if (err) {
        console.error('Erro ao verificar o email no banco de dados:', err);
        return res.status(500).send('Erro interno do servidor');
      }
  
      if (emailResults.length > 0) {
        // Email já em uso
        return res.render('cadastrar', { errorMessage: 'Este email já está em uso. Por favor, escolha outro.' });
    }
  
      // Insere o novo usuário no banco de dados
      const insertUserQuery = 'INSERT INTO login (nome, email, senha) VALUES (?, ?, ?)';
      conexao.query(insertUserQuery, [name,email, password], (err, results) => {
        if (err) {
          console.error('Erro ao inserir no banco de dados:', err);
          return res.status(500).send('Erro interno do servidor');
        }
  
        res.redirect('/');
      });
    });
  });
  

  

// Rota de usuário logado
app.get('/inicio', (req, res) => {
  if (req.session.email) {
    res.render('inicio', { email: req.session.email });
  } else {
    res.redirect('/');
  }
});

app.post('/calculate', (req, res) => {
  
  const { usageTime, appliancePower, state, day } = req.body;
  console.log('Recebendo requisição de cálculo:', req.body);
  console.log(usageTime,appliancePower, state,tariffData[state],day ,"oopa")
  // Adicione aqui a lógica real de cálculo com bas e nos dados recebidos
  // Neste exemplo, apenas multiplicamos os valores para fins ilustrativos
  const monthlyCost = (usageTime * day * appliancePower * tariffData[state] ) / 100; // convertendo a tarifa de centavos para reais
  res.json({ monthlyCost });

});


// Inicia o servidor
app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});