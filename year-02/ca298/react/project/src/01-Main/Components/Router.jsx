import {BrowserRouter} from "react-router-dom";
import {Routes} from "react-router-dom";
import {Route} from "react-router-dom";

import HomePage from "../Pages/HomePage";
import NotFoundPage from "../Pages/NotFoundPage";

import AllDegreesPage from "../../02-Degrees/Pages/AllDegreesPage";
import SingleDegreePage from "../../02-Degrees/Pages/SingleDegreePage";
import CreateDegreePage from "../../02-Degrees/Pages/CreateDegreePage"

import AllCohortsPage from "../../03-Cohorts/Pages/AllCohortsPage";
import SingleCohortsPage from "../../03-Cohorts/Pages/SingleCohortsPage";
import CreateCohortPage from "../../03-Cohorts/Pages/CreateCohortPage";

import AllModulesPage from "../../04-Modules/Pages/AllModulesPage";
import SingleModulePage from "../../04-Modules/Pages/SingleModulePage";
import ModulesByCohortPage from "../../04-Modules/Pages/ModulesByCohortPage";
import CreateModulePage from "../../04-Modules/Pages/CreateModulePage";

import SingleStudentPage from "../../05-Students/Pages/SingleStudentPage";
import CreateStudentPage from "../../05-Students/Pages/CreateStudentPage";
import PutGradePage from "../../05-Students/Pages/PutGradePage";

function Router(){
    return(
        <BrowserRouter>
        
            <Routes>

                <Route path="/" element={<HomePage/>} />
                
                <Route path="/degrees" element={<AllDegreesPage/>} />
                <Route path="/degrees/:DegreeCode" element={<SingleDegreePage/>} />
                <Route path="/newdegree" element={<CreateDegreePage/>} />
                
                <Route path="/cohorts" element={<AllCohortsPage/>} />
                <Route path="/cohorts/:CohortsID" element={<SingleCohortsPage/>} />
                <Route path="/newcohort" element={<CreateCohortPage/>} />
                
                <Route path="/modules" element={<AllModulesPage/>} />
                <Route path="/modules/:ModuleCode" element={<SingleModulePage/>} />
                <Route path="/modules/cohort/:CohortsID" element={<ModulesByCohortPage/>} />
                <Route path="/newmodule" element={<CreateModulePage/>} />

                <Route path="/student" element={<SingleStudentPage/>} />
                <Route path="/newstudent" element={<CreateStudentPage/>} />
                <Route path="/newstudentgrade" element={<PutGradePage/>} />
                
                <Route path="*" element={<NotFoundPage/>}/>

            </Routes>
        
        </BrowserRouter>
    );
}

export default Router;