import Header from "./01-Main/Components/Header";
import Router from "./01-Main/Components/Router";
import Footer from "./01-Main/Components/Footer";
import 'bootstrap/dist/css/bootstrap.min.css';

function App() {
  return (
    <div>
      <Header/>
      <div class="content">
        <Router/>
      </div>
      <Footer/>
    </div>
  );
}

export default App;
