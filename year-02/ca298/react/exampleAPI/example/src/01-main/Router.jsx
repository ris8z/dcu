import {BrowserRouter} from "react-router-dom"
import {Routes} from "react-router-dom"
import {Route} from "react-router-dom"


/**
 * Importing all the component that you want to use as pages
 */
import Home from "./Home"
import Categorys from "../02-category/Categorys"
import New_Category from "../02-category/New_Category"

function Router(){
    return(
        <BrowserRouter>
            <Routes>
                <Route path="/" element={<Home/>}/>
                <Route path="/category" element={<Categorys/>}/>
                <Route path="/newcategory" element={<New_Category/>}/>
            </Routes>
        </BrowserRouter>
    )
}

export default Router;